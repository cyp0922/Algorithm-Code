// 1시간 10분
#include<iostream>
using namespace std;

int N, M;
int dir_x[] = { 0,3,2,1 }; // 북 동 남 서
int tx[] = { 0,-1,0,1 }; // 북 서 남 동
int ty[] = { -1,0,1,0 };
int arr[51][51];
bool visited[51][51];

int space = 0;

void clean(int y, int x, int dir, bool k) {

	// 0북 1동 2남 3서

	// 1. 현재 청소
	if (!visited[y][x] && k == true) {
		visited[y][x] = true;
		space++;
	}

	// 2
	for (int i = 1; i < 5; i++) {
		int d = (dir + i) % 4;
		int ny = y + ty[d];
		int nx = x + tx[d];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			if (!visited[ny][nx] && !arr[ny][nx]) {
				clean(ny, nx, d, true); // 2.a
				return;
			}
		}
	}
	// 2.c
	int ny = y + ty[(dir + 2) % 4];
	int nx = x + tx[(dir + 2) % 4];
	if (ny >= 0 && ny < N && nx >= 0 && nx < M && !arr[ny][nx]) {
		clean(ny, nx, dir, false);
	}
	else return; // 2.d
}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cy, cx, dir;
	cin >> N >> M;
	cin >> cy >> cx >> dir; // 0북 1동 2남 3서
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	clean(cy, cx, dir_x[dir], true);
	cout << space;
}