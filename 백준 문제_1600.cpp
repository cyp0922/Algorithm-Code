#include<iostream>
#include<queue>

using namespace std;

int K, W, H;
int map[200][200];
bool visited[200][200][32];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int hx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int hy[8] = { 2,1,-2,-1,2,1,-2,-1 };

int bfs(int y, int x) {

	queue < pair< pair<int, int>, pair<int, int>>> q;
	q.push({ {y,x},{0,0} }); // y,x,K,cnt
	visited[y][x][0] = true;

	while (!q.empty()) {

		int y = q.front().first.first;
		int x = q.front().first.second;
		int jump = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (y == H - 1 && x == W - 1) return cnt;

		if (jump < K) {

			for (int i = 0; i < 8; i++) {
				int n_x = x + hx[i];
				int n_y = y + hy[i];
				if (n_x >= 0 && n_x < W && n_y >= 0 && n_y < H) {
					if (!map[n_y][n_x] && !visited[n_y][n_x][jump]) {
						visited[n_y][n_x][jump + 1] = true;
						q.push({ {n_y,n_x},{jump + 1,cnt + 1} });
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			if (n_x >= 0 && n_x < W && n_y >= 0 && n_y < H) {
				if (!map[n_y][n_x] && !visited[n_y][n_x][jump]) {
					visited[n_y][n_x][jump] = true;
					q.push({ {n_y,n_x},{jump,cnt + 1} });
				}
			}
		}

	}

	return -1;

}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> K >> W >> H;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}

	cout << bfs(0, 0);

}