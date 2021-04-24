// 40분

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, k;
int arr[21][21];
int scent[2][21][21];

struct is {
	int y;
	int x;
	int dir;
	bool live = true;
};

int dir[400][4][4];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
is shark[401];

void left_scent() {
	
	for (int i = 1; i <= M; i++) {
		if (shark[i].live) {
			int y = shark[i].y;
			int x = shark[i].x;
			scent[0][y][x] = i;
			scent[1][y][x] = k;
		}
	}
}

void shark_move() {

	memset(arr, false, sizeof(arr));

	for (int s = 1; s <= M; s++) {
		if (shark[s].live) {
			int idx = 0;

			int y = shark[s].y;
			int x = shark[s].x;
			bool flag = false;

			while (true) {
				if (idx == 4) {
					flag = true;
					break;
				}
				int d = dir[s][shark[s].dir][idx];
				int ny = y + dy[d];
				int nx = x + dx[d];

				if (0 <= ny && ny < N && 0 <= nx && nx < N && !scent[0][ny][nx]) {
					if (arr[ny][nx]) { // 다른 상어가 있다.
						if (arr[ny][nx] > s) {
							shark[arr[ny][nx]].live = false;
							arr[ny][nx] = s;
							shark[s].y = ny;
							shark[s].x = nx;
							shark[s].dir = d;
						}
						else shark[s].live = false;
						break;
					}
					else {
						arr[ny][nx] = s;
						shark[s].y = ny;
						shark[s].x = nx;
						shark[s].dir = d;
						break;
					}
				}
				else idx++;
			}

			if (flag) {

				idx = 0;
				while (true) {
					if (idx == 4) flag = true;
					int d = dir[s][shark[s].dir][idx];
					int ny = y + dy[d];
					int nx = x + dx[d];

					if (0 <= ny && ny < N && 0 <= nx && nx < N && scent[0][ny][nx] == s) {
						if (arr[ny][nx]) { // 다른 상어가 있다.
							if (arr[ny][nx] > s) {
								shark[arr[ny][nx]].live = false;
								arr[ny][nx] = s;
								shark[s].y = ny;
								shark[s].x = nx;
								shark[s].dir = d;
							}
							else shark[s].live = false;
							break;
						}
						else {
							arr[ny][nx] = s;
							shark[s].y = ny;
							shark[s].x = nx;
							shark[s].dir = d;
							break;
						}
					}
					else idx++;
				}
			}
		}
	}
}

void decrease() {

	for(int y=0; y<N; y++){
		for (int x = 0; x < N; x++) {
			if (scent[1][y][x]) {
				scent[1][y][x] = scent[1][y][x] - 1;
				if (scent[1][y][x] == 0) {
					scent[0][y][x] = 0;
				}
			}
		}
	}
}

int play() {
	for (int p = 1; p <= 1000; p++) {
		left_scent();
		
		shark_move();
		int num = 0;
		for (int i = 1; i <= M; i++) {
			if (shark[i].live) num++;
		}
		if (num == 1) return p;

		decrease();
	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 냄새를 뿌린다
	// 이동
	// 

	cin >> N >> M >> k;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
			shark[arr[y][x]].y = y;
			shark[arr[y][x]].x = x;
		}
	}

	int input;
	for (int i = 1; i <= M; i++) {
		cin >> input;
		shark[i].dir = input - 1;
	}

	for (int s = 1; s <= M; s++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> input;
				dir[s][i][j] = input - 1;
			}
		}
	}
	cout << play();
}