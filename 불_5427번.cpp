#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int T, W, H;
char arr[1001][1001];
bool visited[1001][1001];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int MIN = 1e9;

queue<pair<int, int>> f;
queue<pair<int, int>> sang;

void bfs() {

	int cnt = 0;

	while (!sang.empty()) {
		// 불 번짐
		int fsize = f.size();
		for (int k = 0; k < fsize; k++) {
			int y = f.front().first;
			int x = f.front().second;
			f.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
					if (arr[ny][nx] == '.' || arr[ny][nx] == '@') {
						arr[ny][nx] = '*';
						f.push({ ny,nx });
					}
				}
			}
		}
		cnt++;
		// 상근 이동
		int ssize = sang.size();
		for (int k = 0; k < ssize; k++) {
			int y = sang.front().first; 
			int x = sang.front().second;
			sang.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= H || ny < 0 || nx < 0 || nx >= W) {
					MIN = min(MIN, cnt);
					return;
				}
				if (arr[ny][nx] == '.' && !visited[ny][nx]) {
					visited[ny][nx] = true;
					sang.push({ ny,nx });
				}
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int p = 0; p < T; p++) {

		f = queue<pair<int, int>>();
		sang = queue<pair<int, int>>();
		memset(arr, false, sizeof(arr));
		memset(visited, false, sizeof(visited));
		MIN = 1e9;

		cin >> W >> H;
		string input;

		for (int y = 0; y < H; y++) {
			cin >> input;
			for (int x = 0; x < W; x++) {
				arr[y][x] = input[x];
				if (arr[y][x] == '*') f.push({ y,x });		
				if (arr[y][x] == '@') sang.push({ y,x });
			}
		}

		bfs();

		if (MIN == 1e9) cout << "IMPOSSIBLE\n";
		else cout << MIN << '\n';
	}
}