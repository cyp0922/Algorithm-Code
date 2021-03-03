#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[21][21];
bool visited[21][21];

typedef struct taxi_ {
	int fuel;
	int y;
	int x;
}taxi_;

typedef struct person_ {
	int dx;
	int dy;
	int sx;
	int sy;
}person;

person son[401];
taxi_ taxi;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

bool cmp(pair< pair<int, int>, pair<int, int> > a, pair< pair<int, int>, pair<int, int> > b) {
	// y, x , cnt, fuel

	if (a.second.first == b.second.first) { // 거리가 같을 때	
		if (a.first.first == b.first.first) { // 열이 같을 때
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	}
	return a.second.first < b.second.first;

}

int bfs(int ddy, int ddx) {

	memset(visited, false, sizeof(visited));
	queue<pair< pair<int, int>, pair<int, int> >> q;
	q.push({ {taxi.y,taxi.x} , {0 ,taxi.fuel } });

	while (!q.empty()) {

		int cnt = q.front().second.first;
		int fuel = q.front().second.second;
		int y = q.front().first.first;
		int x = q.front().first.second;
		q.pop();

		if (ddy == y && ddx == x) {
			if (fuel < 0) return -1;
			taxi.fuel = taxi.fuel - cnt;
			taxi.fuel += 2 * cnt;
			taxi.y = y;
			taxi.x = x;
			return 0;
		}
		if (fuel < 0) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !visited[ny][nx] && map[ny][nx] != 1) {
				visited[ny][nx] = true;
				q.push({ {ny,nx }, {cnt + 1 ,fuel - 1} });
			}
		}
	}
	return 1;
}


int bfs_son() {

	memset(visited, false, sizeof(visited));
	vector<pair<pair<int, int>, pair<int, int>> >v;

	visited[taxi.y][taxi.x] = true;
	queue<pair< pair<int, int>, pair<int, int> >> q;
	q.push({ {taxi.y,taxi.x} , {0 ,taxi.fuel } });

	while (!q.empty()) {

		int cnt = q.front().second.first;
		int fuel = q.front().second.second;
		int y = q.front().first.first;
		int x = q.front().first.second;
		q.pop();

		if (fuel < 0) continue;
		if (map[y][x] > 1) { // 손님을 발견
			v.push_back({ {y,x},{cnt,map[y][x]} });
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !visited[ny][nx] && map[ny][nx] != 1) {
				visited[ny][nx] = true;
				q.push({ {ny,nx }, {cnt + 1 ,fuel - 1} });
			}
		}
	}

	if (v.size() == 0) return -1; // 손님이 없을때

	sort(v.begin(), v.end(), cmp);
	taxi.y = v[0].first.first;
	taxi.x = v[0].first.second;
	map[v[0].first.first][v[0].first.second] = 0;
	taxi.fuel = taxi.fuel - v[0].second.first;

	return v[0].second.second -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> taxi.fuel;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}

	cin >> taxi.y >> taxi.x;

	int a, b, c, d;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c >> d;
		son[i].sy = a; son[i].sx; son[i].dy = c; son[i].dx = d;
		map[a][b] = i + 1;
	}

	for (int k = 0; k < M; k++) {

		int num = bfs_son();
		if (num == -1) {
			cout << "-1";
			exit(0);
		}

		if (bfs(son[num].dy, son[num].dx)) {
			cout << "-1";
			exit(0);
		}
	}
	cout << taxi.fuel;

}