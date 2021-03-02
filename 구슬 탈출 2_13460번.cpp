#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int dx[] = { -1,0,1,0 }; //ÁÂ »ó ¿ì ÇÏ
int dy[] = { 0,-1,0,1 }; // 0 1  2 3
int rx_[11];
int ry_[11];
int by_[11];
int bx_[11];
int N, M;
char arr[11][11];
char cmp[11][11][11];
int MIN = 1e9;

void func(int cnt) {

	if (cnt == 11) return;

	for (int i = 0; i < 4; i++) {

		memcpy(cmp[cnt], cmp[cnt - 1], sizeof(cmp[cnt]));

		int suc = 0;
		int ry = ry_[cnt-1]; int rx = rx_[cnt - 1]; 
		int by = by_[cnt-1]; int bx = bx_[cnt - 1];
		bool f_r = true; bool f_b = true;
		int cnt_r = 0; int cnt_b = 0;
		while (f_r || f_b) {

			int nry = ry + dy[i];
			int nrx = rx + dx[i];

			int nby = by + dy[i];
			int nbx = bx + dx[i];

			if (nry >= 0 && nry < N && nrx >= 0 && nrx < M) {

				if (f_r == true && cmp[cnt][nry][nrx] == 'O') {
					suc += 50;
					cmp[cnt][ry][rx] = '.';
					cnt_r++;
					f_r = false;
				}

				if (cmp[cnt][nry][nrx] == '.') {
					cmp[cnt][nry][nrx] = 'R';
					cmp[cnt][ry][rx] = '.';
					ry = nry;
					rx = nrx;
					f_r = true;
					cnt_r++;
				}
				else f_r = false;

			}

			if (nby >= 0 && nby < N && nbx >= 0 && nbx < M) {
				
				if (f_b == true && cmp[cnt][nby][nbx] == 'O') {
					suc += 100;
					cmp[cnt][by][bx] = '.';
					f_b = false;
					cnt_b++;
				}

				if (cmp[cnt][nby][nbx] == '.') {
					cmp[cnt][nby][nbx] = 'B';
					cmp[cnt][by][bx] = '.';
					by = nby;
					bx = nbx;
					f_b = true;
					cnt_b++;
				}
				else f_b = false;
			}

		}

		if (cnt_r == 0 && cnt_b == 0) {
			continue;
		}
		if (suc == 50) {
			MIN = min(MIN, cnt);
			return;
		}
		if (suc == 100 || suc == 150) continue;
		if (cnt >=2 && ry_[cnt - 2] == ry && rx_[cnt - 2] == rx && by_[cnt - 2] == by && bx_[cnt - 2] == bx) continue;

		ry_[cnt] = ry; 
		rx_[cnt] = rx;
		by_[cnt] = by;
		bx_[cnt] = bx;

		func(cnt + 1);

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ¿ÀÁ÷ »¡°£ ±¸½½¸¸
	// '.', '#', 'O', 'R', 'B'
	// ºóÄ­ Àå¾Ö¹° ±¸¸Û »¡°­ ÆÄ¶û
	// 
	cin >> N >> M;
	string input;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'R') {
				ry_[0] = y;
				rx_[0] = x;
			}
			if (arr[y][x] == 'B') {
				by_[0] = y;
				bx_[0] = x;
			}
		}
	}
	memcpy(cmp[0], arr, sizeof(arr));
	func(1);

	if (MIN == 1e9) cout << "-1";
	else cout << MIN;
}