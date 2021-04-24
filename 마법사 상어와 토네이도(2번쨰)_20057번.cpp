#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N;
int arr[501][501];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int px[] = { 1,1,0,0,0,0,-1,-1,-2 };
int py[] = { -1,1,-1,1,2,-2,1,-1,0 };
int pm[] = { 1, 1, 7, 7, 2, 2, 10, 10, 5 };

int play() {

	int y = N / 2 + 1; int x = N / 2 + 1;

	int gap = 1;
	int dir = 0;
	int cnt = 0;
	int sum = 0;
	while (true) {

		for (int g = 1; g <= gap; g++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (y == 1 && x == 1) return sum;

			y = ny;
			x = nx;
			if (arr[ny][nx]) {
				int all = arr[ny][nx];
				int mi = 0;
				arr[ny][nx] = 0;
				for (int j = 0; j < 9; j++) {
					int ky;
					int kx;
					if (dir == 0) {
						ky = ny + py[j];
						kx = nx + px[j];
					}
					else if (dir == 1) {
						ky = ny - px[j];
						kx = nx - py[j];
					}
					else if (dir == 2) {
						ky = ny - py[j];
						kx = nx - px[j];
					}
					else if (dir == 3) {
						ky = ny + px[j];
						kx = nx + py[j];
					}

					mi += all * pm[j] / 100;

					if (1 <= kx && kx <= N && 1 <= ky && ky <= N) {
						arr[ky][kx] += all * pm[j] / 100;
					}
					else sum += all * pm[j] / 100;
				}
				if (1 <= ny + dy[dir] && ny + dy[dir] <= N && 1 <= nx + dx[dir] && nx + dx[dir] <= N) {
					arr[ny + dy[dir]][nx + dx[dir]] += all - mi;
				}
				else sum += all - mi;
			}
		}
		dir = (dir + 1) % 4;
		cnt++;
		if (cnt % 2 == 0) {
			gap++;
			cnt = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}
	cout << play();

}