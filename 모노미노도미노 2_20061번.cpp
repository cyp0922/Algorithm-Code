#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
int arr[10002][3];
int score = 0;
int blue[6][4];
int green[6][4];
//t = 1: 크기가 1×1인 블록을 (y, x)에 놓은 경우
//t = 2: 크기가 1×2인 블록을(y, x), (y, x + 1)에 놓은 경우
//t = 3 : 크기가 2×1인 블록을(y,x), (y + 1, x)에 놓은 경우

void get_score() {

	// 점수 얻을 때
	int cnt_b = 0;
	int cnt_g = 0;
	for (int ny = 3; ny >= 0; ny--) {
		cnt_b = 0;
		cnt_g = 0;
		for (int nx = 0; nx < 4; nx++) {
			if (green[ny][nx]) cnt_g++;
			if (blue[ny][nx]) cnt_b++;
		}

		if (cnt_g == 4) {
			for (int ky = ny; ky < 5; ky++) {
				for (int nx = 0; nx < 4; nx++) {
					green[ky][nx] = green[ky + 1][nx];
					green[ky + 1][nx] = false;
				}
			}
			score++;
		}
		if (cnt_b == 4) {
			for (int ky = ny; ky < 5; ky++) {
				for (int nx = 0; nx < 4; nx++) {
					blue[ky][nx] = blue[ky + 1][nx];
					blue[ky + 1][nx] = false;
				}
			}
			score++;
		}
	}

	// 4칸을 넘었을 때
	bool flag_b = false;
	bool flag_g = false;

	for (int nx = 0; nx < 4; nx++) {
		if (blue[5][nx]== true) {
			for (int ny = 0; ny < 4; ny++) {
				for (int kx = 0; kx < 4; kx++) {
					blue[ny][kx] = blue[ny + 2][kx];
					blue[ny + 2][kx] = false;
				}
			}
		}

		if (green[5][nx]== true) {
			for (int ny = 0; ny < 4; ny++) {
				for (int kx = 0; kx < 4; kx++) {
					green[ny][kx] = green[ny + 2][kx];
					green[ny + 2][kx] = false;
				}
			}
		}
	}

	for (int nx = 0; nx < 4; nx++) {

		if (blue[4][nx] == true) {
			for (int ny = 0; ny < 4; ny++) {
				for (int kx = 0; kx < 4; kx++) {
					blue[ny][kx] = blue[ny + 1][kx];
					blue[ny + 1][kx] = false;
				}
			}
		}

		if (green[4][nx]== true) {
			for (int ny = 0; ny < 4; ny++) {
				for (int kx = 0; kx < 4; kx++) {
					green[ny][kx] = green[ny + 1][kx];
					green[ny + 1][kx] = false;
				}
			}
		}
	}

}

int count() {

	int cnt = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (green[y][x]) cnt++;
			if (blue[y][x]) cnt++;
		}
	}

	return cnt;
}

void block_psuh(int t, int y, int x) {

	// green은 동일 
	// blue는 x,y자리 변경

	//// green
	int idx_g = 0;
	for (int cy = 0; cy < 4; cy++) {
		if ((t == 3 || t == 1) && green[cy][x]) idx_g = cy + 1;
		else if (t == 2 && (green[cy][x] || green[cy][x + 1])) idx_g = cy + 1;
	}

	if (t == 1) green[idx_g][x] = true;
	else if (t == 2) green[idx_g][x] = green[idx_g][x + 1] = true;
	else if (t == 3) green[idx_g][x] = green[idx_g + 1][x] = true;

	// blue

	int nx = 3 - y;
	int idx_b = 0;
	for (int cy = 0; cy < 4; cy++) {
		if ((t == 2 || t == 1) && blue[cy][nx]) idx_b = cy + 1;
		else if (t == 3 && (blue[cy][nx] || blue[cy][nx - 1])) idx_b = cy + 1;
	}

	if (t == 1) blue[idx_b][nx] = true;
	else if (t == 2) blue[idx_b][nx] = blue[idx_b + 1][nx] = true;
	else if (t == 3) blue[idx_b][nx] = blue[idx_b][nx - 1] = true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//  한 행이나 열이 사라지면 1점
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; // 쿠기 ,x y
	}

	for (int p = 1; p <= N; p++) {

		block_psuh(arr[p][0], arr[p][1], arr[p][2]); //t x y
		get_score();
	}

	cout << score << "\n" << count();
}