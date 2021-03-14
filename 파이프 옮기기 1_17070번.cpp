#include<iostream>

using namespace std;

int N;
int arr[17][17];

int dx[] = { 0, 1, 1 }; // 아래, 대각선, 오른쪽
int dy[] = { 1,1,0 };
int ans;

void dfs(int cy, int cx, int dir) {

	if (cy == N && cx == N) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {

		if (dir == 0 && i == 2) continue;
		else if (dir == 2 && i == 0) continue;


		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {

			if (i != 1 && !arr[ny][nx]) {
				dfs(ny, nx, i);
			}

			if (i == 1 && !arr[cy + 1][cx] && !arr[cy][cx + 1] && !arr[cy + 1][cx + 1]) {
				dfs(ny, nx, i);
				continue;
			}

		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	visited[1][1] = true;
	visited[1][2] = true;

	dfs(1, 2, 2);

	cout << ans;

}