// 1시간 5분
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
char arr[11][11][11];
int b[11][2];
int r[11][2];
int MIN = 1e9;
int dx[] = { 0, 1, 0, -1 }; // 북 동 남 서
int dy[] = { -1,0,1,0 };

struct jam {
	int y;
	int x;
};

bool play(int y, int x, int dir, int cnt) {

	int ny;
	int nx;
	while (true) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (arr[cnt][ny][nx] == '.') { // 이동
			arr[cnt][ny][nx] = arr[cnt][y][x];
			arr[cnt][y][x] = '.';
		}
		else if (arr[cnt][ny][nx] == 'O') { // 목적지 도착
			arr[cnt][y][x] = '.';
			return true;
		}
		else {
			if (arr[cnt][y][x] == 'R') {
				r[cnt][0] = y;
				r[cnt][1] = x;
			}
			if (arr[cnt][y][x] == 'B') {
				b[cnt][0] = y;
				b[cnt][1] = x;
			}
			return false;
		}
		y = ny;
		x = nx;
	}
}

int move(int cnt, int dir) {

	memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
	jam blue;
	jam red;
	blue.y = b[cnt - 1][0]; blue.x = b[cnt - 1][1];
	red.y = r[cnt - 1][0]; red.x = r[cnt - 1][1];

	// 북 동 남 서
	bool bf = false;
	bool rf = false;
	if (dir == 0) { // 북
		if (blue.y < red.y) {
			bf = play(blue.y, blue.x, dir, cnt);
			rf = play(red.y, red.x, dir, cnt);
		}
		else {
			rf = play(red.y, red.x, dir, cnt);
			bf = play(blue.y, blue.x, dir, cnt);
		}
	}
	else if (dir == 1) {// 동
		if (blue.x > red.x) {
			bf = play(blue.y, blue.x, dir, cnt);
			rf = play(red.y, red.x, dir, cnt);
		}
		else {
			rf = play(red.y, red.x, dir, cnt);
			bf = play(blue.y, blue.x, dir, cnt);
		}
	}
	else if (dir == 2) {// 남
		if (blue.y > red.y) {
			bf = play(blue.y, blue.x, dir, cnt);
			rf = play(red.y, red.x, dir, cnt);
		}
		else {
			rf = play(red.y, red.x, dir, cnt);
			bf = play(blue.y, blue.x, dir, cnt);
		}
	}
	else if (dir == 3) {// 서
		if (blue.x < red.x) {
			bf = play(blue.y, blue.x, dir, cnt);
			rf = play(red.y, red.x, dir, cnt);
		}
		else {
			rf = play(red.y, red.x, dir, cnt);
			bf = play(blue.y, blue.x, dir, cnt);
		}
	}

	if (bf == true && rf == true) return 2; // 동시에 들어감
	else if (rf == true) return 1; // 정답
	else if (bf == true) return 3; // 실패
	else return 0; //다음 진행
}

void func(int cnt, int dir) {

	if (cnt > 10) return;

	if (cnt >= 1) {
		int num = move(cnt, dir);
		if (num == 1) {
			MIN = min(MIN, cnt);
			return;
		}
		else if (num > 1) return;
	}

	for (int i = 0; i < 4; i++) {
		func(cnt + 1, i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 동시 x
	string input;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			arr[0][y][x] = input[x];
			if (arr[0][y][x] == 'R') {
				r[0][0] = y;
				r[0][1] = x;
			}
			else if (arr[0][y][x] == 'B') {
				b[0][0] = y;
				b[0][1] = x;
			}
		}
	}

	func(0, 0);
	cout << (MIN == 1e9 ? -1 : MIN);
}