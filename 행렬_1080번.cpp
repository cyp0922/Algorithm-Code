#include<iostream>
using namespace std;

int N, M;
int cnt = 0;

int arr[51][51];
int cmp[51][51];

int main() {

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &cmp[y][x]);
		}
	}

	for (int y = 0; y < N - 2; y++) {
		for (int x = 0; x < M - 2; x++) {

			if (arr[y][x] != cmp[y][x]) { // 다시 y,x 로 돌아오지않으므로 같지 않다면 뒤집어준다
				cnt++;
				for (int j = y; j < y + 3; j++) {
					for (int i = x; i < x + 3; i++) {
						if (arr[j][i]) arr[j][i] = 0;
						else arr[j][i] = 1;
					}
				}
			}
		}
	}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (cmp[y][x] != arr[y][x]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << cnt;
}