#include<iostream>
#include<cstring>
using namespace std;

int N;
int map[6][21][21];
int MAX = 0;

void func(int step, int dir) {

	if (step == 6) {

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (MAX < map[step-1][y][x]) MAX = map[step-1][y][x];
			}
		}
		return;

	}

	if (step > 0) {

		memcpy(map[step], map[step - 1], sizeof(map[step-1]));

		if (dir == 0) {

			for (int y = 0; y < N; y++) {
				int x = 0;
				int nx = x + 1;

				while (nx < N) {
	
					if (map[step][y][nx] == 0) {
						nx++;
						continue;
					}

					if (map[step][y][x] == map[step][y][nx]) {
						map[step][y][x] += map[step][y][nx];
						map[step][y][nx] = 0;
					}
					
					else if (map[step][y][x] == 0) {
						map[step][y][x] = map[step][y][nx];
						map[step][y][nx] = 0;
						continue;
					}

					else if (map[step][y][x] && map[step][y][nx] && !map[step][y][x+1]) {
						map[step][y][x+1] = map[step][y][nx];
						map[step][y][nx] = 0;
					}
					x++;
					nx++;

				}
			}

		}

		else if (dir == 1) {

			for (int x = 0; x < N; x++) {
				int y = 0;
				int ny = y + 1;

				while (ny < N) {

					if (map[step][ny][x] == 0) {
						ny++;
						continue;
					}

					else if (map[step][y][x] == map[step][ny][x]) {
						map[step][y][x] += map[step][ny][x];
						map[step][ny][x] = 0;
					}

					else if (map[step][y][x] == 0) {
						map[step][y][x] = map[step][ny][x];
						map[step][ny][x] = 0;
						continue;
					}

					else if (map[step][y][x] && map[step][ny][x] && !map[step][y+1][x]) {
						map[step][y+1][x] = map[step][ny][x];
						map[step][ny][x] = 0;
					}
					y++;
					ny++;

				}
			}

		}

		else if (dir == 2) {

			for (int y = 0; y < N; y++) {
				int x = N - 1;
				int nx = x - 1;

				while (nx >= 0) {

					if (map[step][y][nx] == 0){
						nx--;
						continue;
					}

					if (map[step][y][x] == map[step][y][nx]) {
						map[step][y][x] += map[step][y][nx];
						map[step][y][nx] = 0;
					}

					else if (map[step][y][x] == 0) {
						map[step][y][x] = map[step][y][nx];
						map[step][y][nx] = 0;
						continue;
					}

					else if (map[step][y][x] && map[step][y][nx] && !map[step][y][x-1]) {
						map[step][y][x -1] = map[step][y][nx];
						map[step][y][nx] = 0;

					}
					x--;
					nx--;

				}
			}

		}


		else if (dir == 3) {

			for (int x = 0; x<N; x++) {
				int y = N - 1;
				int ny = y - 1;

				while (ny >= 0) {

					if (map[step][ny][x] == 0){
						ny--;
						continue;
					}

					if (map[step][y][x] == map[step][ny][x]) {
						map[step][y][x] += map[step][ny][x];
						map[step][ny][x] = 0;
					}

					else if (map[step][y][x] == 0) {
						map[step][y][x] = map[step][ny][x];
						map[step][ny][x] = 0;
						continue;
					}


					else if (map[step][y][x] && map[step][ny][x] && !map[step][y - 1][x]) {
						map[step][y - 1][x] = map[step][ny][x];
						map[step][ny][x] = 0;

					}
					y--;
					ny--;

				}
			}

		}
	}

	for (int i = 0; i < 4; i++) {

		func(step + 1, i);

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[0][y][x];
		}
	}

	func(0, 0);

	cout << MAX;
}