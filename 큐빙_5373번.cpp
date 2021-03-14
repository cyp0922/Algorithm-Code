#include<iostream>
#include<cstring>
using namespace std;

int N;

char side[3][12];
char front[12][3];
int cmp[3][3];
int smp[3];

void cube(char w, char dir) {
	//U: À­ ¸é, D: ¾Æ·§ ¸é, F: ¾Õ ¸é, B: µÞ ¸é, L: ¿ÞÂÊ ¸é, R: ¿À¸¥ÂÊ

	if (w == 'U') {

		if (dir == '+') {
			for (int i = 0; i < 3; i++) smp[i] = side[0][i];

			for (int i = 0; i < 9; i++) side[0][i] = side[0][i + 3];

			for (int i = 0; i < 3; i++) side[0][i + 9] = smp[i];

			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i][j] = front[2 - j][i]; // ½Ã°è ¹æÇâ
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i][j];
				}
			}
			// °ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) front[j + 3][i - 3] = side[j][i];
			}
			for (int j = 0; j < 3; j++) {
				for (int i = 9; i < 12; i++)  front[11 - j][11 - i] = side[j][i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = side[0][11 - i];

			for (int i = 11; i >= 3; i--) side[0][i] = side[0][i - 3];

			for (int i = 0; i < 3; i++) side[0][i] = smp[2 - i];

			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i][j] = front[j][2 - i]; // ½Ã°è ¹æÇâ
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i][j];
				}
			}
			// °ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) front[j + 3][i - 3] = side[j][i];
			}
			for (int j = 0; j < 3; j++) {
				for (int i = 9; i < 12; i++)  front[11 - j][11 - i] = side[j][i];
			}
		}
	}

	else if (w == 'D') {

		if (dir == '+') {
			for (int i = 0; i < 3; i++) smp[i] = side[2][11 - i];

			for (int i = 11; i >= 3; i--) side[2][i] = side[2][i - 3];

			for (int i = 0; i < 3; i++) side[2][2 - i] = smp[i];

			// 
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 6][j] = front[8 - j][i - 6]; // ½Ã°è ¹æÇâ
				}
			}
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 6][j];
				}
			}
			// °ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) front[j + 3][i - 3] = side[j][i];
			}
			for (int j = 0; j < 3; j++) {
				for (int i = 9; i < 12; i++)  front[11 - j][11 - i] = side[j][i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = side[2][i];

			for (int i = 0; i < 9; i++) side[2][i] = side[2][i + 3];

			for (int i = 0; i < 3; i++) side[2][i + 9] = smp[i];

			// 
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 6][j] = front[j + 6][8 - i]; // ¹Ý½Ã°è ¹æÇâ
				}
			}
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 6][j];
				}
			}
			// °ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) front[j + 3][i - 3] = side[j][i];
			}
			for (int j = 0; j < 3; j++) {
				for (int i = 9; i < 12; i++)  front[11 - j][11 - i] = side[j][i];
			}
		}
	}


	else if (w == 'L') {

		if (dir == '+') {

			for (int i = 0; i < 3; i++) smp[i] = front[9 + i][0];

			for (int i = 11; i >= 3; i--) front[i][0] = front[i - 3][0];

			for (int i = 0; i < 3; i++) front[i][0] = smp[i];

			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i][j] = side[2 - j][i];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					side[i][j] = cmp[i][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = front[i][0];

			for (int i = 0; i < 9; i++) front[i][0] = front[i + 3][0];

			for (int i = 0; i < 3; i++) front[i + 9][0] = smp[i];

			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i][j] = side[j][2 - i];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					side[i][j] = cmp[i][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}

		}

	}

	else if (w == 'R') {

		if (dir == '+') {
			for (int i = 0; i < 3; i++) smp[i] = front[i][2];

			for (int i = 0; i < 9; i++) front[i][2] = front[i + 3][2];

			for (int i = 0; i < 3; i++) front[i + 9][2] = smp[i];

			//
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[j][i - 6] = side[8 - i][6 + j];
				}
			}
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					side[j][i] = cmp[j][i - 6];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = front[9 + i][2];

			for (int i = 11; i >= 3; i--) front[i][2] = front[i - 3][2];

			for (int i = 0; i < 3; i++) front[i][2] = smp[i];

			// 
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[j][i - 6] = side[i - 6][8 - j];
				}
			}
			for (int i = 6; i < 9; i++) {
				for (int j = 0; j < 3; j++) {
					side[j][i] = cmp[j][i - 6];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}
		}

	}

	else if (w == 'F') {

		if (dir == '+') {
			for (int i = 0; i < 3; i++) smp[i] = front[2][i];

			for (int i = 0; i < 3; i++) front[2][2 - i] = side[i][2];
			for (int i = 0; i < 3; i++) side[i][2] = front[6][i];
			for (int i = 0; i < 3; i++) front[6][i] = side[2 - i][6];
			for (int i = 0; i < 3; i++) side[i][6] = smp[i];

			// 
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 3][j] = front[5 - j][i - 3];
				}
			}
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 3][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = front[2][i];

			for (int i = 0; i < 3; i++) front[2][i] = side[i][6];
			for (int i = 0; i < 3; i++) side[i][6] = front[6][2 - i];
			for (int i = 0; i < 3; i++) front[6][i] = side[i][2];
			for (int i = 0; i < 3; i++) side[i][2] = smp[2 - i];

			// 
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 3][j] = front[3 + j][5 - i];
				}
			}

			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 3][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 3; i < 6; i++) {
				for (int j = 0; j < 3; j++) side[i - 3][j + 3] = front[i][j];
			}
		}
	}

	else if (w == 'B') {

		if (dir == '+') {
			for (int i = 0; i < 3; i++) smp[i] = front[8][i];

			for (int i = 0; i < 3; i++) front[8][i] = side[i][0];
			for (int i = 0; i < 3; i++) side[i][0] = front[0][2 - i];
			for (int i = 0; i < 3; i++) front[0][i] = side[i][8];
			for (int i = 0; i < 3; i++) side[i][8] = smp[2 - i];

			// 
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 9][j] = front[11 - j][i - 9];
				}
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 9][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}
		}
		else {
			for (int i = 0; i < 3; i++) smp[i] = front[8][i];

			for (int i = 0; i < 3; i++) front[8][i] = side[2 - i][8];
			for (int i = 0; i < 3; i++) side[i][8] = front[0][i];
			for (int i = 0; i < 3; i++) front[0][i] = side[2 - i][0];
			for (int i = 0; i < 3; i++) side[i][0] = smp[i];

			//
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) {
					cmp[i - 9][j] = front[9 + j][11 - i];
				}
			}
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) {
					front[i][j] = cmp[i - 9][j];
				}
			}
			//°ãÄ¡´Â ºÎºÐ
			for (int i = 9; i < 12; i++) {
				for (int j = 0; j < 3; j++) side[11 - i][11 - j] = front[i][j];
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// À­¸é-Èò»ö, ¾Æ·¡-³ë¶û ¾Õ¸é-»¡°­ µÞ¸é-¿À·»Áö ¿ÞÂÊ-ÃÊ·Ï, ¿À¸¥ÂÊ-ÆÄ¶û

	cin >> N;
	char com;
	char dir;
	int ro;
	for (int p = 0; p < N; p++) {

		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 3; x++) {
				if (y >= 0 && y < 3) front[y][x] = 'w';
				else if (3 <= y && y < 6) front[y][x] = 'r';
				else if (6 <= y && y < 9) front[y][x] = 'y';
				else if (9 <= y && y < 12) front[y][x] = 'o';
			}
		}

		for (int x = 0; x < 12; x++) {
			for (int y = 0; y < 3; y++) {
				if (0 <= x && x < 3) side[y][x] = 'g';
				else if (3 <= x && x < 6) side[y][x] = 'r';
				else if (6 <= x && x < 9) side[y][x] = 'b';
				else if (9 <= x && x < 12) side[y][x] = 'o';
			}
		}

		cin >> ro;
		for (int h = 0; h < ro; h++) {
			cin >> com >> dir;
			cube(com, dir);
		}
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cout << front[y][x];
			}
			cout << "\n";
		}
	}
}