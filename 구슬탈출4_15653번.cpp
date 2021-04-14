#include<iostream>
#include<queue>
using namespace std;

int N, M; 
char arr[11][11];
bool visited[11][11][11][11];

struct is {
	int ry;
	int rx; 
	int by;
	int bx; 
	int cnt;
};

int dx[] = { -1,0,1,0 }; // аб го ©Л ╩С
int dy[] = { 0,1,0,-1 };
int ry, rx, by, bx;
queue<is> q;

bool r_move(int dir) {
	int gap = 1;
	while (true) {

		int ny = ry + gap*dy[dir];
		int nx = rx + gap*dx[dir];
		//cout <<"r "<< ny << " " << nx << endl;
		if (arr[ny][nx] == '.' && !(ny == by && nx == bx)) gap++;
		else if (arr[ny][nx] == 'O') {
			ry = -1;
			rx = -1;
			return true;
		}
		else {
			ry = ry + (gap - 1) * dy[dir];
			rx = rx + (gap - 1) * dx[dir];
			return false;
		}
	}
}

bool b_move(int dir) {

	int gap = 1;
	while (true) {
		int ny = by + gap * dy[dir];
		int nx = bx + gap * dx[dir];

		if (arr[ny][nx] == '.' && !(ny == ry && nx == rx)) gap++;
		else if (arr[ny][nx] == 'O') {
			by = -1;
			bx = -1;
			return true;
		}
		else {
			by = by + (gap - 1) * dy[dir];
			bx = bx + (gap - 1) * dx[dir];
			return false;
		}
	}
}

void bfs() {

	while (!q.empty()) {

		for (int i = 0; i < 4; i++) {

			ry = q.front().ry;
			rx = q.front().rx;
			by = q.front().by;
			bx = q.front().bx;
			int cnt = q.front().cnt;
			bool rflag = false;
			bool bflag = false;

			rflag = false;
			bflag = false;

			if (i == 0) { // аб
				if (rx < bx) {
					rflag = r_move(i);
					bflag = b_move(i);
				}
				else {
					bflag = b_move(i);
					rflag = r_move(i);
				}
			}
			else if (i == 1) {// го
				if (ry > by) {
					rflag = r_move(i);
					bflag = b_move(i);
				}
				else {
					bflag = b_move(i);
					rflag = r_move(i);
				}
			}
			else if (i ==2) {// ©Л
				if (rx > bx) {
					rflag = r_move(i);
					bflag = b_move(i);
				}
				else {
					bflag = b_move(i);
					rflag = r_move(i);
				}
			}
			else if (i == 3) {// ╩С
				if (ry < by) {
					rflag = r_move(i);
					bflag = b_move(i);
				}
				else {
					bflag = b_move(i);
					rflag = r_move(i);
				}
			}

			if (rflag == false && bflag == false) {
				if (!visited[ry][rx][by][bx]) {
					q.push({ ry,rx,by,bx,cnt + 1 });
					visited[ry][rx][by][bx] = true;
				}
			}
			else if (rflag == true && bflag == false ) {
				cout << cnt;
				exit(0);
			}
		}
		q.pop();
	}
	cout << -1;
}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	string input;
	int ay, ax, zy, zx;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'R') {
				arr[y][x] = '.';
				ay = y;
				ax = x;
			}
			else if (arr[y][x] == 'B') {
				arr[y][x] = '.';
				zy = y;
				zx = x;
			}
		}
	}
	visited[ay][ax][zy][zx] = true;
	q.push({ ay,ax,zy,zx,1 });

	bfs();
}