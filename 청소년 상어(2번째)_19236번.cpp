// 45ºÐ
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct fi {
	int y;
	int x;
	int dir;
	bool live = true;
};

fi fish[16][17];
int arr[16][4][4];
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int MAX = 0;

void fish_move(int cnt) {

	for (int i = 1; i <= 16; i++) {
		if (fish[cnt][i].live) {
			int y = fish[cnt][i].y;
			int x = fish[cnt][i].x;
			int dir = fish[cnt][i].dir;

			for (int j = 0; j < 8; j++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (0 <= ny && ny < 4 && 0 <= nx && nx < 4 && arr[cnt][ny][nx] != -1) {
					if (arr[ny][nx] == 0) { // ºóÄ­ÀÏ¶§
						arr[cnt][ny][nx] = i;
						arr[cnt][y][x] = 0;
						fish[cnt][i].y = ny;
						fish[cnt][i].x = nx;
						fish[cnt][i].dir = dir;
					}
					else if (arr[ny][nx] > 0) { // ¹°°í±â Á¸Àç
						int temp = arr[cnt][ny][nx];
						arr[cnt][ny][nx] = i;
						fish[cnt][i].y = ny;
						fish[cnt][i].x = nx;
						fish[cnt][i].dir = dir;

						arr[cnt][y][x] = temp;
						fish[cnt][temp].y = y;
						fish[cnt][temp].x = x;
						
					}
					break;
				}
				dir = (dir + 1) % 8;
			}
		}
	}
}

void func(int sy, int sx, int sum ,int cnt) {

	memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
	memcpy(fish[cnt], fish[cnt - 1], sizeof(fish[cnt]));

	int temp = arr[cnt][sy][sx];
	MAX = max(MAX, sum + temp); 
	arr[cnt][sy][sx] = -1;
	int sd = fish[cnt][temp].dir;
	fish[cnt][temp].live = false;

	fish_move(cnt);

	arr[cnt][sy][sx] = 0;

	int gap = 1;
	while (true) {
		int ny = sy + gap * dy[sd];
		int nx = sx + gap * dx[sd];
		if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
			if(arr[cnt][ny][nx]) func(ny, nx, sum + temp, cnt + 1);
		}
		else break;
		gap++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num,dir;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> arr[0][y][x] >> dir;
			fish[0][arr[0][y][x]].y = y;
			fish[0][arr[0][y][x]].x = x;
			fish[0][arr[0][y][x]].dir = dir - 1;
		}
	}

	func(0, 0, 0, 1);
	cout << MAX; 
}