// 55ºÐ
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, M;
bool arr[102][102];
int visited[102][102];
int dir[] = { 8,4,2,1 };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int lx[] = { -1,1,-1,-1 };
int ly[] = { 1,-1,-1,1 };
int rx[] = { 1,1,1,-1 };
int ry[] = { 1,1,-1,-1 };

vector<int> room;
vector<bool> check;

void bfs(int cy, int cx, int num) {

	queue< pair<int, pair<int, int>> > q;
	visited[cy][cx] = num;
	q.push({ 1,{cy,cx} });
	int MAX = 1;
	while (!q.empty()) {

		int y = q.front().second.first;
		int x = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + 2 * dy[i];
			int nx = x + 2 * dx[i];
			int ky = y + dy[i];
			int kx = x + dx[i];
			if (1 <= ny && ny < 2 * N && 1 <= nx && nx < 2 * M && !visited[ny][nx]) {
				if (arr[ky][kx] == 0) {
					MAX++;
					visited[ny][nx] = num;
					q.push({ cnt + 1,{ ny,nx } });
				}
			}
		}
	}
	room.push_back(MAX);
	check.push_back(0);
}

void func() {

	int MAX = 0;

	for (int y = 1; y < 2 * N; y++) {
		for (int x = 1; x < 2 * M; x++) {
			if (arr[y][x] == 1) {
				int sum = 0;
				for (int i = 0; i < check.size(); i++) check[i] = false;

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (visited[ny][nx] && !check[visited[ny][nx] - 1]) {
						check[visited[ny][nx] - 1] = true;
						sum += room[visited[ny][nx] - 1];
					}
				}
				MAX = max(sum, MAX);
			}
		}
	}
	cout << MAX << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 1 ¼­ 2 ºÏ 4 µ¿ 8 ³²

	int input;
	cin >> M >> N;
	for (int y = 1; y < 2 * N; y += 2) {
		for (int x = 1; x < 2 * M; x += 2) {
			cin >> input;
			int idx = 0;
			while (input != 0) {
				if (input - dir[idx] >= 0) {
					int ny = y + dy[idx];
					int nx = x + dx[idx];
					arr[ny][nx] = true;
					arr[y + ly[idx]][x + lx[idx]] = true;
					arr[y + ry[idx]][x + rx[idx]] = true;
					input -= dir[idx];
				}
				else idx++;
			}
		}
	}

	int k = 1;
	for (int y = 1; y < 2 * N; y += 2) {
		for (int x = 1; x < 2 * M; x += 2) {
			if (!visited[y][x]) {
				bfs(y, x, k);
				k++;
			}
		}
	}

	cout << room.size() << "\n";
	int ans = 0;
	for (int i = 0; i < room.size(); i++) {
		if (ans < room[i]) ans = room[i];
	}
	cout << ans << "\n";
	func();
}