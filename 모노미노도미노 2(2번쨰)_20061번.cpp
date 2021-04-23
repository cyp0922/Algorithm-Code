#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
bool map[2][6][4];

int fall(int cx, int cy, int color, int t) {

	if (color == 1) cx = 3 - cx;

	if (t == 1) {
		for (int y = 1; y < 6; y++) {
			if (y == 5 && map[color][y][cx] == false) map[color][y][cx] = true;
			else if (map[color][y][cx] == false) continue;
			else {
				map[color][y - 1][cx] = true;
				break;
			}
		}
	}
	else if (t == 2) {
		if (color == 0) {
			for (int y = 2; y < 6; y++) {
				if (y == 5 && map[color][y][cx] == false && map[color][y - 1][cx] == false) {
					map[color][y][cx] = true;
					map[color][y - 1][cx] = true;
				}
				else if (map[color][y][cx] == false && map[color][y - 1][cx] == false) {
					continue;
				}
				else {
					map[color][y - 1][cx] = true;
					map[color][y - 2][cx] = true;
					break;
				}
			}
		}
		else if (color == 1) {
			for (int y = 1; y < 6; y++) {
				if (y == 5 && map[color][y][cx - 1] == false && map[color][y][cx] == false) {
					map[color][y][cx] = true;
					map[color][y][cx - 1] = true;
				}
				else if (map[color][y][cx - 1] == false && map[color][y][cx] == false) {
					continue;
				}
				else {
					map[color][y - 1][cx] = true;
					map[color][y - 1][cx - 1] = true;
					break;
				}
			}
		}
	}
	else if (t == 3) {
		if (color == 0) {
			for (int y = 1; y < 6; y++) {
				if (y == 5 && map[color][y][cx + 1] == false && map[color][y][cx] == false) {
					map[color][y][cx] = true;
					map[color][y][cx + 1] = true;
				}
				else if (map[color][y][cx + 1] == false && map[color][y][cx] == false) {
					continue;
				}
				else {
					map[color][y - 1][cx] = true;
					map[color][y - 1][cx + 1] = true;
					break;
				}
			}
		}
		else if (color == 1) {
			for (int y = 2; y < 6; y++) {
				if (y == 5 && map[color][y][cx] == false && map[color][y - 1][cx] == false) {
					map[color][y][cx] = true;
					map[color][y - 1][cx] = true;
				}
				else if (map[color][y][cx] == false && map[color][y - 1][cx] == false) {
					continue;
				}
				else {
					map[color][y - 1][cx] = true;
					map[color][y - 2][cx] = true;
					break;
				}
			}
		}
	}
	// Á¡¼ö È¹µæ
	int score = 0;
	int b = 1;
	for (int a = 0; a < b; a++) {
		for (int y = 5; y >= 2; y--) {
			int num = 0;
			for (int x = 0; x < 4; x++) {
				if (map[color][y][x] == true) {
					num++;
				}
			}
			if (num == 4) {
				b++;
				score++;
				for (int cy = y - 1; cy >= 0; cy--) {
					for (int x = 0; x < 4; x++) {
						map[color][cy + 1][x] = map[color][cy][x];
						map[color][cy][x] = 0;
					}
				}
				break;
			}
		}
	}
	// Ä­¿¡ ÀÖ´Â °Íµé
	int idx = 0;
	for (int y = 1; y >= 0; y--) {
		for (int x = 0; x < 4; x++) {
			if (map[color][y][x] == true) {
				idx++;
				break;
			}
		}
	}
	if (idx > 0) {
		for (int y = 5 - idx; y >= 0; y--) {
			for (int x = 0; x < 4; x++) {
				map[color][y + idx][x] = map[color][y][x];
				map[color][y][x] = 0;
			}
		}
	}
	return score;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int y, x, t;

	int sum = 0; 
	// t = 1 . t = 2 1x2  t =3 2 x 1 
	for (int i = 1; i <= N; i++) {
		cin >>t >> x >> y;

		sum += fall(x, y, 0, t);
		sum += fall(y, 3 - x, 1, t);
	}
	int cnt = 0;
	for (int y = 5; y >= 2; y--) {
		for (int x = 0; x < 4; x++) {
			for (int k = 0; k <= 1; k++) {
				if (map[k][y][x]) cnt++;
			}
		}
	}
	cout << sum << "\n" << cnt;
}
