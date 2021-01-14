#include<iostream>

using namespace std;

int map[21][21];

int dx[] = { 1,-1,0,0 }; // 동서북남
int dy[] = { 0,0,-1,1 };

int h_x[3];
int h_y[4];

int N, M; //세로 가로
int K,x,y; // 명령어 갯수 주사위 좌표

// 백준 입력시 x,y 입력이 아닌 ,, y,x로 이루어져있다.

void func(int c) {

	int dir_x = x + dx[c-1];
	int dir_y = y + dy[c-1];

	if (dir_x < 0 || dir_x >= M || dir_y < 0 || dir_y >= N) return;

	x = dir_x;
	y = dir_y;
	//cout << x << " " << y << endl;

	int temp;
	if (c == 1) { // 동
		temp = h_x[2];
		h_x[2] = h_x[1];
		h_x[1] = h_x[0];
		h_x[0] = h_y[3];
		h_y[1] = h_x[1];//
		h_y[3] = temp;
	}
	else if (c == 2) {
		temp = h_x[0];
		h_x[0] = h_x[1];
		h_x[1] = h_x[2];
		h_x[2] = h_y[3];
		h_y[1] = h_x[1];
		h_y[3] = temp;
	}
	else if (c == 3) {
		temp = h_y[0];
		h_y[0] = h_y[1];
		h_y[1] = h_y[2];
		h_y[2] = h_y[3];
		h_y[3] = temp;
		h_x[1] = h_y[1];
	}
	else if (c == 4) {
		temp = h_y[3];
		h_y[3] = h_y[2];
		h_y[2] = h_y[1];
		h_y[1] = h_y[0];
		h_y[0] = temp;
		h_x[1] = h_y[1];
	}
	
	if (map[y][x] == 0) {
		map[y][x]= h_y[3];
	}
	else {
		h_y[3] = map[y][x];
		map[y][x] = 0;
	}


	cout << h_y[1] << endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> y >> x >> K;


	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			cin >> map[j][i];
		}
	}

	int input;

	for (int i = 0; i < K; i++) {
		cin >> input;
		func(input);
	}

}