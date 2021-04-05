#include<iostream>
#include<cstring>
using namespace std;

int N, M, R;
int arr[101][101];
int cmp[101][101];

void print() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void turn(int k) {

	memcpy(cmp,arr,sizeof(cmp));

	if (k == 1) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				arr[y][x] = cmp[N -1 - y][x];
			}
		}
	}
	else if (k == 2) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				arr[y][x] = cmp[y][M - 1 - x];
			}
		}
	}
	else if (k == 3) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				arr[y][x] = cmp[M - 1 - x][y];
			}
		}
	}
	else if (k == 4) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				arr[y][x] = cmp[x][N - 1 - y];
			}
		}
	}
	else if (k == 5) {


		// 1 -> 2
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky][kx + M / 2] = cmp[ky][kx];
			}
		}

		// 2 -> 3
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky + N / 2][kx + M / 2] = cmp[ky][kx + M / 2];
			}
		}

		// 3 -> 4
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky + N / 2][kx] = cmp[ky + N / 2][kx + M / 2];
			}
		}

		// 4 -> 1
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky][kx] = cmp[ky + N / 2][kx];
			}
		}

	}

	else if (k == 6) {

		// 1 -> 4
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[N / 2 + ky][kx] = cmp[ky][kx];
			}
		}

		// 4 -> 3
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky + N / 2][kx + M / 2] = cmp[N / 2 + ky][kx];
			}
		}

		// 3 -> 2
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky][M / 2 + kx] = cmp[ky + N / 2][kx + M / 2];
			}
		}

		// 2 -> 1
		for (int ky = 0; ky < N / 2; ky++) {
			for (int kx = 0; kx < M / 2; kx++) {
				arr[ky][kx] = cmp[ky][M / 2 + kx];
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	int input;
	for (int i = 0; i < R; i++) {
		cin >> input;
		if (input == 4 || input == 3) {
			int temp = 0;
			temp = N;
			N = M;
			M = temp;
		}
		turn(input);
	}
	print();

}