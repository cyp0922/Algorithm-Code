// 45Ка
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;

int arr[501][501];
bool visited[501][501];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int MAX = 0;
int hx[8][3] = { {1,0,0},{-1,0,0},{1,1,2},{1,1,2},{0,1,0},{0,-1,0},{-1,-1,-2},{-1,-1,-2} };
int hy[8][3] = { {-1,-1,-2},{-1,-1,-2},{0,-1,0},{0,1,0},{1,1,2},{1,1,2},{0,-1,0},{0,1,0} };

void check(int cy, int cx) {

	int sum = arr[cy][cx];
	for (int num = 0; num < 8; num++) {
		sum = arr[cy][cx];
		for (int i = 0; i < 3; i++) {
			int ny = cy + hy[num][i];
			int nx = cx + hx[num][i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M) sum += arr[ny][nx];

			else break;

			if (i == 2) MAX = max(MAX, sum);
		}
	}
}

void dfs(int cy, int cx, int cnt, int sum) {

	if (cnt == 4) {
		MAX = max(MAX, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {

		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(ny, nx, cnt + 1, sum + arr[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = true;
			dfs(y, x, 1, arr[y][x]);
			visited[y][x] = false;
			check(y, x);
		}
	}
	cout << MAX;
}