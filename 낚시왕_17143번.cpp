#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int R, C, M;
int map[101][101];
int temp[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

typedef struct shark_ {

	int y;
	int x; 
	int dir;
	int speed;
	int size;

}shark;


vector<shark> v;

void move() {

	for (int i = 0; i < v.size(); i++) {
		
		if (v[i].size == -1) continue;

		int y = v[i].y;
		int x = v[i].x;
		int dir = v[i].dir -1;
		
		int ny = abs(v[i].speed * dy[dir]);
		int nx = abs(v[i].speed * dx[dir]);

		int left;

		if (nx == 0) { // 상하  R

			left = ny % (2 * R - 2);
			
			for (int i = 0; i < left; i++) {
				y += dy[dir];
				if (y < 1) y = 2, dir = 1;
				else if (y > R) y = R - 1 , dir = 0;
				
			}
			
		}

		else { // 좌우

			left = nx % (2 * C - 2);

			for (int i = 0; i < left; i++) {
				x += dx[dir];

				if (x < 1) x = 2 , dir = 2;
				else if (x > C) x = C - 1 , dir = 3;
				
			}

		}

		// 겹치는 상어 비교
		if (temp[y][x]) {
			if (v[temp[y][x] - 1].size > v[i].size)
			{
				v[i].size = -1;
				v[i].y = 0;
				v[i].x = 0;
			}
			else if (v[temp[y][x] - 1].size < v[i].size) {
				v[temp[y][x] - 1].size = -1;
				v[temp[y][x] - 1].y = 0;
				v[temp[y][x] - 1].x = 0;
				
				v[i].x = x;
				v[i].y = y;
				v[i].dir = dir + 1;


				temp[y][x] = i + 1;
			}
		}
		else {
			v[i].x = x;
			v[i].y = y;
			v[i].dir = dir + 1;

			temp[y][x] = i + 1;
		}
	}

	memcpy(map, temp, sizeof(temp));
	memset(temp, false, sizeof(temp));

}

int fishing(int cur) {

	for (int i = 1; i <= R; i++) {
		if (map[i][cur]) {
			int temp = v[map[i][cur] - 1].size;
			v[map[i][cur] - 1].size = -1;
			v[map[i][cur] - 1].x = 0;
			v[map[i][cur] - 1].y = 0;

			map[i][cur] = 0;

			return temp;

		}
	}

	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// r은 행, c는 열

	// 상어 속도 칸/초 경계를 넘는 경우 방향을 반대로 다시 속력 유지
	// 한칸에 상어가 두마리 이상 x 크기가 가장 큰 상어가 잡아먹는다
	// 격자판 크기 R,C 상어수 M
	
	// 잡은 상어 크기의 합

	int r, c, s, d, z; // r,c 위치 s속력 d이동방향 z크기
	int cur = 0; // 낚시꾼 위치

	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark sh;
		sh.y = r, sh.x = c;
		sh.speed = s;
		sh.dir = d;
		sh.size = z;

		map[r][c] = i;
		
		v.push_back(sh);
	}
	// 입력

	int cnt = 0;

	for (int p = 1; p <=C; p++)
	{
		cnt += fishing(p);
		move();

	}

	cout << cnt << endl;

}