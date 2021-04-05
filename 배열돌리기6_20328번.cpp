#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int N, L, R;
int len;
int arr[129][129];
int cmp[129][129];

void print() {
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
}

void turn(int k, int l) {

	int gap = pow(2, l);

	if (5 <= k && k <= 8) memcpy(cmp, arr, sizeof(cmp));

	for (int y = 0; y < len; y += gap) {
		for (int x = 0; x < len; x += gap) {


			if (1 <= k && k <= 4) {
				// 복사
				int cy = 0, cx = 0;
				for (int ny = y; ny < y + gap; ny++) {
					cx = 0;
					for (int nx = x; nx < x + gap; nx++) {
						cmp[cy][cx] = arr[ny][nx];
						cx++;
					}
					cy++;
				}

				if (k == 1) { // 상하 반전

					for (int ky = 0; ky < gap; ky++) {
						for (int kx = 0; kx < gap; kx++) {
							arr[y + ky][x + kx] = cmp[gap - 1 - ky][kx];
						}
					}
				}
				else if (k == 2) { //좌우 반전

					for (int ky = 0; ky < gap; ky++) {
						for (int kx = 0; kx < gap; kx++) {
							arr[y + ky][x + kx] = cmp[ky][gap - 1 - kx];
						}
					}
				}
				else if (k == 3) { //90 회전 오른쪽

					for (int ky = 0; ky < gap; ky++) {
						for (int kx = 0; kx < gap; kx++) {
							arr[y + ky][x + kx] = cmp[gap - 1 - kx][ky];
						}
					}
				}
				else if (k == 4) { //90 회전 왼쪽

					for (int ky = 0; ky < gap; ky++) {
						for (int kx = 0; kx < gap; kx++) {
							arr[y + ky][x + kx] = cmp[kx][gap - 1 - ky];
						}
					}
				}
			}

			else if (5 <= k && k <= 8) {

				if (k == 5) {
					for (int ny = 0; ny < gap; ny++) {
						for (int nx = 0; nx < gap; nx++) {
							arr[ny + y][nx + x] = cmp[len - gap - y + ny][nx + x];
						}
					}
				}
				else if (k == 6) {
					for (int ny = 0; ny < gap; ny++) {
						for (int nx = 0; nx < gap; nx++) {
							arr[ny + y][nx + x] = cmp[y + ny][len - gap - x + nx];
						}
					}
				}
				else if (k == 7) {
					for (int ny = 0; ny < gap; ny++) {
						for (int nx = 0; nx < gap; nx++) {
							arr[ny + y][nx + x] = cmp[len - gap - x + ny][y + nx];
						}
					}
				}
				else if (k == 8) {
					for (int ny = 0; ny < gap; ny++) {
						for (int nx = 0; nx < gap; nx++) {
							arr[ny + y][nx + x] = cmp[ny + x][len - gap - y + nx];
						}
					}
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> R;

	len = pow(2, N);
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			cin >> arr[y][x];
		}
	}

	int a, b;
	for (int i = 0; i < R; i++) {
		cin >> a >> b;
		turn(a, b);
	}
	print();

}