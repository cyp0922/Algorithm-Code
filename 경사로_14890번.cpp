#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, L;
int map[101][101];

int dx[] = { 0,1 }; // 아래 , 오른쪽
int dy[] = { 1,0 };
int func(int y, int x, int d) {

	int ny;
	int nx;
	int cnt = 1;

	while (true) {

		ny = y + dy[d];
		nx = x + dx[d];

		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {

			if (map[y][x] == map[ny][nx]) {
				cnt++;
				x = nx;
				y = ny;
				continue;
			}
			else if (map[y][x] -1 == map[ny][nx]) { // 현재 계단 보다 낮을때
				
				cnt = 1;
				int cy;
				int cx;

				while (true) {

					if (cnt == L) break;

					cx = nx + dx[d];
					cy = ny + dy[d];

					if (cy >= 0 && cy < N && cx >= 0 && cx < N) {
						
						if (map[ny][nx] == map[cy][cx]) cnt++;
						else return 0;

					}
					else return 0;
					
					nx = cx;
					ny = cy;

				}

				cnt = 0;
				x = nx;
				y = ny;

				continue;
			}

			else if (map[y][x] +1 == map[ny][nx] ) { // 현재 계단 보다 높을때
				
				if (cnt >= L) {
					cnt = 1;
				}
				else return 0;

				x = nx;
				y = ny;
				continue;

			}
			else return 0;

		}
		else break;

	}

	return 1;

}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			cin >> map[j][i];
		}
	}

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += func(0, i, 0); // 아래방향
	}
	for (int i = 0; i < N; i++) {
		sum += func(i, 0 ,1); // 오른방향
	}

	cout << sum;

}