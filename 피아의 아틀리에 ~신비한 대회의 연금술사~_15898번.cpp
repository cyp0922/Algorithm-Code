#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct item {

	int num = 0;
	char color = 'W';

}item;

item store[4][5][5];
item arr[10][4][4];
int n;
int	MAX = 0;
bool visited[10];
int dx[] = { 0,1,0,1 };
int dy[] = { 0,0,1,1 };

void func(int x);
void position(int cnt, int k);

void position(int cnt, int k) {

	item cmp[4][4];
	memcpy(store[cnt], store[cnt - 1], sizeof(store[cnt]));
	memcpy(cmp, arr[k], sizeof(cmp));

	int nx, ny;
	item copy[4][4];

	for (int a = 0; a < 4; a++) { // 회전 for문

		for (int y = 0; y < 4; y++) { // 회전
			for (int x = 0; x < 4; x++) {
				copy[y][x] = cmp[x][3 - y];
			}
		}

		for (int i = 0; i < 4; i++) { // 위치 이동 for 문
			for (int y = 0; y < 4; y++) {
				ny = y + dy[i];
				for (int x = 0; x < 4; x++) {

					nx = x + dx[i];

					store[cnt][ny][nx].num += copy[y][x].num;

					if (store[cnt][ny][nx].num > 9) store[cnt][ny][nx].num = 9;
					else if (store[cnt][ny][nx].num < 0) store[cnt][ny][nx].num = 0;

					if (copy[y][x].color != 'W') store[cnt][ny][nx].color = copy[y][x].color;

				}
			}

			func(cnt + 1);

			memcpy(store[cnt], store[cnt - 1], sizeof(store[cnt]));
		}
		memcpy(cmp, copy, sizeof(copy));

	}

}


void func(int cnt) {

	if (cnt == 4) {
		int r = 0; 
		int b = 0; 
		int g = 0; 
		int ye = 0;

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				char temp = store[cnt - 1][y][x].color;
				int temp_num = store[cnt - 1][y][x].num;

				if (store[cnt - 1][y][x].color == 'R') r += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'B') b += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'G') g += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'Y') ye += store[cnt - 1][y][x].num;
			}

		}

		MAX = max(MAX, 7 * r + 5 * b + 3 * g + 2 * ye);
		return;
	}

	for (int i = 0; i < n; i++) {

		if (!visited[i]) {
			visited[i] = true;
			position(cnt, i);
			visited[i] = false;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 5x5 격자 서로 다른 재료 3개 
	// 재료 후보는 10개 이하
	// 각 칸에는 품질을 나타내는 숫자와 원소를 나타내느 색이 칠해져 있다.
	// 초기에는 모든 칸의 품질은 0, 원소는 흰색이다. 재료는 4x4 모양으로 생겼으며,
	// 재료의 i행 j열에는 2가지 정보가 있다.
	// 효능: 가마 한 칸의 품질을 바꾸는 -9이상 9이하의 정수
	// 원소 : 가마 한칸의 원소를 바꿀 수 있는 색(R,B,Y,W)
	// 재료가 위치한 가마의 격자칸에 있는 품질과 원소값ㅇ느 바뀔 수 있다.
	// 격자의 품질은 재료의 효능이 더해진다. 더한 뒤의 값이 음수인 경우 0으로 9초과인 경우 9로 바뀐다.\
	// 격자의 색은 재료의 원소가 흰색인 경우 그대로, 아닌 경우 재료의 원소와 같은 색으로 칠해진다. 

	// 재료 3개를 모두 넣어야만 폭탄이 만들어지며, 폭탄의 품질은 다음과 같이 계산한다. 
	// 폭탄의 품질 7R + 5B + 3G + 2Y 

	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> arr[i][y][x].num;
			}
		}

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> arr[i][y][x].color;
			}
		}

	}

	func(1);
	cout << MAX;

}
