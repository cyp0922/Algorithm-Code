#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

int N, M, T, K, a, b;
char map[101][101];
char cmp[101][101];

int count(int ny, int nx) {

	int cnt = 0;

	for (int y = ny - K; y <= ny + K; y++) {
		for (int x = nx - K; x <= nx + K; x++) {

			if (x >= 0 && x < M && y >= 0 && y < N) {
				if (map[y][x] == '*') cnt++;
			}

		}
	}
	if (map[ny][nx] == '*') cnt--;

	return cnt;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> T;
	cin >> K >> a >> b;

	string input;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			map[y][x] = input[x];
		}
	}

	for (int p = 0; p < T; p++) {

		memcpy(cmp, map, sizeof(cmp));

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {

				int cnt = count(y, x);
				if (map[y][x] == '*' && a <= cnt && cnt <= b) { // 생존
					cmp[y][x] = '*';
				}
				else if (map[y][x] == '*' && cnt < a) { // 고독
					cmp[y][x] = '.';
				}
				else if (map[y][x] == '*' && b < cnt) { // 과밀
					cmp[y][x] = '.';
				}
				else if (map[y][x] == '.' && cnt > a && cnt <= b) {
					cmp[y][x] = '*';
				}
			}
		}

		memcpy(map, cmp, sizeof(map));

	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}


}