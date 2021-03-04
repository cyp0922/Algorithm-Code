#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M, K;

typedef struct shark_ {
	int y;
	int x;
	int dir;
	bool live = true;
};

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int map[21][21];
int cmp[21][21];
int leave[21][21][2];
int fis[400][5][5];

shark_ shark[401];

void smell_left() {
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == true) {
			leave[shark[i].y][shark[i].x][0] = i;
			leave[shark[i].y][shark[i].x][1] = K;
		}
	}
}

void smell_bye() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (leave[y][x][1]) {
				leave[y][x][1]--;

				if (leave[y][x][1] == 0) leave[y][x][0] = 0;
			}
		}
	}
}

void move() {

	memset(cmp, false, sizeof(cmp));

	for (int i = 1; i <= M; i++) {
		if (shark[i].live == true) {

			bool flag = false;
			int y = shark[i].y;
			int x = shark[i].x;
			int dir = shark[i].dir;

			for (int k = 1; k <= 4; k++) { // 주변에 냄새가 없을때
				int ny = y + dy[fis[i][dir][k]-1];
				int nx = x + dx[fis[i][dir][k]-1];
				int ndir = fis[i][dir][k];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || leave[ny][nx][1] !=0 ) continue;

				if (cmp[ny][nx] != 0) { // 칸에 상어가 있다면

					if (cmp[ny][nx] > i) {
						shark[cmp[ny][nx]].live = false;
						shark[i].y = ny;
						shark[i].x = nx;
						shark[i].dir = ndir;
						cmp[ny][nx] = i;
					}
					else shark[i].live = false;	

					flag = true;
					break;
				}
				else {
					shark[i].y = ny;
					shark[i].x = nx;
					shark[i].dir = ndir;
					cmp[ny][nx] = i;

					flag = true;
					break;
				}
			}
			if (flag == false) { // 자신의 냄새로
				for (int k = 1; k <= 4; k++) { // 주변에 냄새가 없을때
					int ny = y + dy[fis[i][dir][k] - 1];
					int nx = x + dx[fis[i][dir][k] - 1];
					int ndir = fis[i][dir][k];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N || leave[ny][nx][0] != i) continue;

					if (cmp[ny][nx] != 0) { // 칸에 상어가 있다면

						if (cmp[ny][nx] > i) {
							shark[cmp[ny][nx]].live = false;
							shark[i].y = ny;
							shark[i].x = nx;
							shark[i].dir = ndir;
							cmp[ny][nx] = i;
						}
						else shark[i].live = false;

						flag = true;
						break;
					}
					else {
						shark[i].y = ny;
						shark[i].x = nx;
						shark[i].dir = ndir;
						cmp[ny][nx] = i;

						flag = true;
						break;
					}
				}
			}
		}
	}

	memcpy(map, cmp, sizeof(map));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 1번이 가장 강력
	// 1초마다 상하좌우 자신의 냄새를 칸에 뿌린다, k번 이동하고 나면 사라진다. 

	// 인접한 칸 중 아무 냄새가 없는 칸으로 방향을 잡는다.
	// 그런 칸이 없으면 자신의 냄새가 있는 칸으로 방향을 잡는다.
	// 우선순위는 상어마다 다르다.

	cin >> N >> M >> K;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] > 0) {
				shark[map[y][x]].y = y;
				shark[map[y][x]].x = x;
			}
		}
	}

	for (int i = 1; i <= M; i++) cin >> shark[i].dir;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) cin >> fis[i][j][k];
		}
	}

	// 입력
	int cnt = 0;
	for (int p = 1; p <= 1000; p++) {

		smell_left();

		move();

		cnt = 0;
		for (int i = 1; i <= M; i++) if (shark[i].live == true) cnt++;

		if (cnt == 1) { 
			cout << p; 
			exit(0);
		}

		smell_bye();
	}
	cout << "-1";
}