// 1시간 소요

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int N, M, R;
int arr[102][102];
int cmp[102][102];
int dx[] = { -1,0,1,0 }; // 서 북 동 남
int dy[] = { 0,-1,0,1 };

int score = 0;

void fall(int cy, int cx, int dir) {

	int k = arr[cy][cx];
	int i = 0;
	while (i < k) {
		int ny = cy + i * dy[dir];
		int nx = cx + i * dx[dir];

		if (1 <= ny && ny <= N && 1 <= nx && nx <= M) {
			if (arr[ny][nx]) {
				if (arr[ny][nx] > k - i) k = arr[ny][nx] + i;
				arr[ny][nx] = 0;
				score++;
			}
		}
		else break;
		i++;
	}
}

void attack(int cy, int cx, int dir) {

	if (dir == 'W') fall(cy, cx, 0);
	else if (dir == 'N') fall(cy, cx, 1);
	else if (dir == 'E') fall(cy, cx, 2);
	else if (dir == 'S') fall(cy, cx, 3);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	
	cin >> N >> M >> R;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
			cmp[y][x] = arr[y][x];
		}
	}
	
	int ay, ax;
	char dir;
	int by, bx;

	for(int i=0; i<R; i++ ){
		cin >> ay >> ax >> dir;
		cin >> by >> bx;

		attack(ay, ax, dir);
		arr[by][bx] = cmp[by][bx];
	}

	cout << score << "\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (arr[y][x]) cout << 'S';
			else cout << 'F';
			cout << ' ';
		}
		cout << "\n";
	}
}