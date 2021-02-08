#include<iostream>
#include<algorithm>

using namespace std;

typedef struct fish_ {

	int dir;
	int y;
	int x;
	bool live;

}fish_;

typedef struct shark {
	int y;
	int x;
	int dir;
	int eat;

}shark;

int MAX = 0;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int arr[18][4][4];
fish_ fish[18][17];
shark s;

void move_fish(int cnt, int sy, int sx) {

	int y;
	int x;

	for (int i = 1; i <= 16; i++) {
	
		if (fish[cnt][i].live == true) {
			y = fish[cnt][i].y;
			x = fish[cnt][i].x;
			int d = fish[cnt][i].dir;
			int c = 0;
			bool flag = false;
			while (c < 7) {

				int ny = y + dy[fish[cnt][i].dir];
				int nx = x + dx[fish[cnt][i].dir];

				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !(nx == sx && ny == sy)) {

					fish_ temp;
					int cn;
					if (arr[cnt][ny][nx] != 0) {
						temp.y = fish[cnt][arr[cnt][ny][nx]].y;
						temp.x = fish[cnt][arr[cnt][ny][nx]].x;
						fish[cnt][arr[cnt][ny][nx]].y = fish[cnt][i].y;
						fish[cnt][arr[cnt][ny][nx]].x = fish[cnt][i].x;
						fish[cnt][i].y = temp.y;
						fish[cnt][i].x = temp.x;
					}
					else {
						fish[cnt][i].y = ny;
						fish[cnt][i].x = nx;
					}


					cn = arr[cnt][ny][nx];
					arr[cnt][ny][nx] = arr[cnt][y][x];
					arr[cnt][y][x] = cn;
					flag = true;
					break;
				}

				fish[cnt][i].dir = (fish[cnt][i].dir + 1) % 8;
				c++;
			}

			if(flag == false) fish[cnt][i].dir = d;
		}
	}
}

void func(int cnt) {

	shark temp;
	MAX = max(MAX, s.eat);

	int y = s.y;
	int x = s.x;
	int d = s.dir;

	memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
	memcpy(fish[cnt], fish[cnt - 1], sizeof(fish[cnt]));
	temp = s;

	for (int k = 1; k <= 3; k++) {

		int nx = x + k * dx[d];
		int ny = y + k * dy[d];

		if (arr[cnt][ny][nx] == 0) continue;

		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {

			s.eat += arr[cnt][ny][nx];
			s.x = nx; s.y = ny;
			s.dir = fish[cnt][arr[cnt][ny][nx]].dir;
			fish[cnt][arr[cnt][ny][nx]].live = false;
			arr[cnt][ny][nx] = 0;

			move_fish(cnt, s.y, s.x);

			func(cnt + 1);

			memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
			memcpy(fish[cnt], fish[cnt - 1], sizeof(fish[cnt]));
			s = temp;

		}
		else continue;
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// x행번호  y 열번호
	// 번호 1~ 16 같은번호 x
	// 방향 8가지 
	// (0,0) 방향은 있던 물고기의 방향과 같다
	// 물고기는 번호가 작은 물고기부터 순서대로 이동
	// 이동할 수 있는 칸은 빈칸과 다른 물고기가 있는 칸
	// 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는칸
	// 각 물기는 방향이 이동할 수 없는 칸을 향할때 까지 방향을 반시계 45도 회전
	// 이동할 수 있는 칸이 없으면 이동 x
	// 물고기 이동 후 상어 이동 . 한 번에 여러개의 칸을 디동 가틍
	// 상어가 물고기가 있는 칸으로 이동하면 그, 물고기를 먹고 물고기의 방향을 가진다.
	// 이동하는  중에 지나가는 칸의 물거기를 먹지않는다. 물고기가 없는 칸으로 이동  x
	// 상어가 이동할 수 있는 칸이 없으면 공간을 벗어나 집으로간다. 
	// 상어 이동 후 몰고기 이동

	int a, b;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> a >> b;
			arr[0][y][x] = a;
			fish[0][a].dir = b - 1;
			fish[0][a].y = y;
			fish[0][a].x = x;
			fish[0][a].live = true;
		}
	}

	s.x = 0;  s.y = 0;
	s.eat = arr[0][0][0];
	s.dir = fish[0][arr[0][0][0]].dir;
	fish[0][arr[0][0][0]].live = false;
	arr[0][0][0] = 0;

	move_fish(0, s.y, s.x);
	func(1);

	cout << MAX;
}