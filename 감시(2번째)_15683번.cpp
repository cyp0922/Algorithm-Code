#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int arr[9][8][8];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

struct is {
	int y;
	int x;
	int num;
};
vector<is> cam;
int MIN = 1e9;

void see(int cnt, int k) {

	int y = cam[cnt - 1].y;
	int x = cam[cnt - 1].x;
	int num = cam[cnt - 1].num;

	int a; int b; int c;
	if (num == 1) {
		a = 0; b = 0; c = 1;
	}
	else if (num == 2) {
		a = 0; b = 2; c = 2;
	}
	else if (num == 3) {
		a = 0; b = 1; c = 1;
	}
	else if (num == 4) {
		a = 0; b = 2; c = 1;
	}
	else if (num == 5) {
		a = 0; b = 3; c = 1; 
	}

	for (int i = a; i <= b; i += c) {
		int gap = 1;
		while (true) {
			int ny = y + gap * dy[(i + k) % 4];
			int nx = x + gap * dx[(i + k) % 4];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && arr[cnt][ny][nx] != 6) {
				if (arr[cnt][ny][nx] == 0) arr[cnt][ny][nx] = 7;
			}
			else break;
			gap++;
		}
	}
}

void func(int cnt) {

	if (cnt -1 == cam.size()) {

		int temp = 0; 
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (arr[cnt - 1][y][x] == 0) temp++;
			}
		}
		MIN = min(MIN, temp);
		return;
	}
	
	if (cam[cnt - 1].num == 5) {
		memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
		see(cnt, 0);
		func(cnt + 1);
	}
	else if (cam[cnt - 1].num == 2) {
		for (int i = 0; i < 2; i++) {
			memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
			see(cnt, i);
			func(cnt + 1);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
			see(cnt, i);
			func(cnt + 1);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[0][y][x];
			if (arr[0][y][x] >= 1 && arr[0][y][x] <= 5) {
				cam.push_back({ y,x,arr[0][y][x] });
			}
		}
	}
	func(1);
	cout << MIN;
}