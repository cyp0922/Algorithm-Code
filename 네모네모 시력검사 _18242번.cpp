#include<iostream>
using namespace std; 

int N, M;
char arr[101][101];

int cx[] = { 1,0 };
int cy[] = { 0,1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			arr[y][x] = input[x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == '#') {
				
				int cnt = 0;

				int rcy = y; int rcx = x;
				int ry = y;  int rx = x;
				int r_cnt = 0;

				int dcy = y; int dcx = x;
				int dy = y ; int dx = x;
				int d_cnt = 0;

				while (r_cnt == d_cnt) {
					r_cnt = 0;
					d_cnt = 0;

					while (arr[rcy][rcx] == arr[ry][rx]) {
						r_cnt++;
						ry = ry + cy[0];
						rx = rx + cx[0];
						if (ry >= N || rx >= M) break;
					}
					while (arr[dcy][dcx] == arr[dy][dx]) {
						d_cnt++;
						dy = dy + cy[1];
						dx = dx + cx[1];
						if (dy >= N || dx >= M) break;
					}
					cnt++;
					rcy = dy - cy[1]; rcx = dx - cx[1]; dcy = ry - cy[0]; dcx = rx - cx[0];
					ry = rcy; rx = rcx; dy = dcy; dx = dcx;
				}

				if (cnt == 1) {
					if (r_cnt > d_cnt) cout << "LEFT";
					else if (r_cnt < d_cnt) cout << "UP";
				}
				else if (cnt == 2) {
					if (r_cnt > d_cnt) cout << "RIGHT";
					else if (r_cnt < d_cnt) cout << "DOWN";
				}

				exit(0);
			}
		}
	}
}