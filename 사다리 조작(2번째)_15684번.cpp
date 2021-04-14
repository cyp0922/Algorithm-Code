// 40분

#include<iostream>
using namespace std;

int N, M, H;
bool arr[32][13];
int limit = 1;

bool down(int num) {

	int x = num;
	for (int y = 1; y <= H; y++) {
		if (arr[y][x]) { // 오른쪽
			x = x + 1;
		}
		else if (arr[y][x - 1]) {
			x = x - 1;
		}
	}

	if (x == num)return true;
	return false; 
}

void func(int cy, int cx, int cnt) {
	
	if (cnt == limit) {

		for (int i = 1; i <= N; i++) {
			if (!down(i)) return;
		}
		cout << cnt << endl;
		exit(0);
	}

	for (int y = cy; y <= H; y++) {
		for (int x = cx; x <= N-1; x++) {
			if (!arr[y][x] && !arr[y][x-1] && !arr[y][x + 1]) {
				arr[y][x] = true; 
				func(y, x + 2, cnt + 1); 
				arr[y][x] = false;
			}
		}
		cx = 1;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> H; 
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = true;
	}

	for (int k = 0; k <= 3; k++) {
		limit = k;
		func(1, 1, 0);
	}
	cout << -1;
}