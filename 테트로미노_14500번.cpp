#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int map[501][501];
int MAX = 0;
int visited[501][501];
int dx[] = { -1,0,1,0 }; // ÁÂ »ó ¿ì ÇÏ
int dy[] = { 0,-1,0,1 };

void dfs(int cnt, int sum, int y, int x) {

	if (cnt == 4) {
		MAX = max(MAX, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {

		int ny = y + dy[i];
		int nx = x + dx[i];

		if (cnt == 1) { // ¤Ç ¤Ì ¤¿¤Ã

			int j = (i + 1) % 4;
			int k = (i + 3) % 4;

			int ry = ny + dy[j];
			int rx = nx + dx[j];
			int ly = ny + dy[k];
			int lx = nx + dx[k];

			int nnx = nx + dy[i];
			int nny = ny + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
				if (nny >= 0 && nny < N && nnx >= 0 && nnx < M && !visited[nny][nnx]) {
					if (ry >= 0 && ry < N && rx >= 0 && rx < M && !visited[ry][rx]) {
						MAX = max(MAX, sum + map[ry][rx] + map[nny][nnx] + map[ny][nx]);
					}
					if (ly >= 0 && ly < N && lx >= 0 && lx < M && !visited[ly][lx]) {
						MAX = max(MAX, sum + map[ly][lx] + map[nny][nnx] + map[ny][nx]);
					}
				}
			}
		}

		if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(cnt + 1, sum + map[ny][nx], ny, nx);
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
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = true;
			dfs(1,map[y][x],y, x);
			visited[y][x] = false;
		}
	}
	cout << MAX;
}