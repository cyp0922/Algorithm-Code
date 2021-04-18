#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N, M;
char arr[31][31];
bool visited[31][31];
int MIN = 1e9;
vector<pair<int, int >> v;
int dy[] = { -1,0,1,0 }; // ºÏ ¼­ ³² µ¿
int dx[] = { 0,-1,0,1 };

void dfs(int cy, int cx, int cnt, int dir, int dis) {

	if (dis == v.size()) {
		MIN = min(MIN, cnt);
		return;
	}

	visited[cy][cx] = true;

	int ny = cy + dy[dir];
	int nx = cx + dx[dir];
	if (0 <= ny && ny < N && 0 <= nx && nx < M) {
		if (!visited[ny][nx] && arr[ny][nx] == '.') {
			dfs(ny, nx, cnt, dir, dis + 1);
		}
		else{
			for (int i = 0; i < 4; i++) {
				int ky = cy + dy[i];
				int kx = cx + dx[i];
				if (0 <= ky && ky < N && 0 <= kx && kx < M) {
					if (!visited[ky][kx] && arr[ky][kx] == '.') {
						dfs(ky, kx, cnt + 1, i, dis + 1);
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ky = cy + dy[i];
			int kx = cx + dx[i];
			if (0 <= ky && ky < N && 0 <= kx && kx < M) {
				if (!visited[ky][kx] && arr[ky][kx] == '.') {
					dfs(ky, kx, cnt + 1, i, dis + 1);
				}
			}
		}
	}
	visited[cy][cx] = false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k = 0;
	while (cin >> N >> M) {
		k++;
		string input;
		MIN = 1e9;
		v.clear();
		for (int y = 0; y < N; y++) {
			cin >> input;
			for (int x = 0; x < M; x++) {
				arr[y][x] = input[x];
				if (arr[y][x] == '.') {
					v.push_back({ y,x });
				}
			}
		}

		if (v.size() == 1) MIN = 0;
		else{
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < 4; j++) {
					dfs(v[i].first, v[i].second, 1, j, 1);
				}
			}
		}
		cout << "Case " << k << ": " << (MIN==1e9 ? -1 : MIN) << endl;
	}
}