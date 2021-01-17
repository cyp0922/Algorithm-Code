#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, L, R;
int map[51][51];
bool visited[51][51];
int cnt;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int bfs(int y_, int x_) {

	queue<pair<int, int>> q;
	queue<pair<int, int>> store;
	q.push({ y_,x_ });
	store.push({ y_,x_ });
	cnt = 1;
	int sum = map[y_][x_];
	visited[y_][x_] = true;

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {

				int diff = abs(map[y][x] - map[ny][nx]);

				if (!visited[ny][nx] && diff >= L && diff <= R) {
					cnt++;
					sum += map[ny][nx];
					visited[ny][nx] = true;
					q.push({ ny,nx });
					store.push({ ny,nx });
				}

			}

		}


	}

	int temp = sum / cnt;

	while (!store.empty()) {
		int y = store.front().first;
		int x = store.front().second;
		store.pop();
		map[y][x] = temp;
	}

	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	int open = 0;
	bool flag = false;

	while (true) {

		flag = false;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {

				if (visited[y][x] == 0) {

					bfs(y, x);
					if (cnt > 1) flag = true;
					
				}

			}
		}

		if (flag == false) break;

		open++;
		memset(visited, false, sizeof(visited));

	}

	cout << open;

}