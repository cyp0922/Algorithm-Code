// 1½Ã°£ 30ºÐ

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int N, M;
char arr[1501][1501];
bool visited[1501][1501];
vector<pair<int, int>> pos;
queue<pair<int, int>> melt;
queue<pair<int, int>> back;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

bool back_bfs(queue<pair<int, int>> q) {

	back = queue<pair<int, int>>();
	visited[pos[0].first][pos[0].second] = true;
	q.push({ pos[0].first,pos[0].second });

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
				if (arr[ny][nx] == '.') {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
				else if (arr[ny][nx] == 'L') return true;
				else if (arr[ny][nx] == 'X') {
					if (!back.empty() && back.back().first == y && back.back().second == x) continue;
					back.push({ y,x });
				}
			}
		}
	}
	return false;
}

void bfs(int cy, int cx) {

	queue<pair<int, int>> q;
	visited[cy][cx] = true;
	q.push({ cy,cx });

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
				if (arr[ny][nx] == '.' || arr[ny][nx] == 'L') {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
				else if (arr[ny][nx] == 'X') {
					if (!melt.empty() && melt.back().first == y && melt.back().second == x) continue;
					melt.push({ y,x });
				}
			}
		}
	}
}

void melt_land() {

	int cnt = melt.size();

	for (int k = 0; k < cnt; k++) {

		int y = melt.front().first;
		int x = melt.front().second;
		melt.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (arr[ny][nx] == 'X') {
					melt.push({ ny,nx });
					arr[ny][nx] = '.';
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < M; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'L') pos.push_back({ y,x });
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visited[y][x] && (arr[y][x] == '.' || arr[y][x] == 'L')) bfs(y, x);
		}
	}

	memset(visited, false, sizeof(visited));

	int cnt = 0;
	back.push({ pos[0].first,pos[0].second });

	while (true) {
		if (back_bfs(back)) break;
		melt_land();
		cnt++;
	}
	cout << cnt;
}