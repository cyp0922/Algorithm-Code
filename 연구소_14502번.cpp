// 30Ка

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int arr[9][9];
bool visited[9][9];
int MAX = 0;
int zero = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs(int cy, int cx) {

	int k = 0;
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
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !arr[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = true;
				k++;
				q.push({ ny,nx });
			}
		}
	}
	return k;
}

void func(int cy, int cx, int cnt) {

	if (cnt == 3) {
		int sum = 0;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (arr[y][x] == 2 && !visited[y][x]) {
					sum += bfs(y, x);
				}
			}
		}
		MAX = max(MAX, zero - sum - 3);

		return;
	}

	bool flag = false;

	for (int y = cy; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == 0) {

				if (flag == false && x >= cx) {
					arr[y][x] = 1;
					func(y, x + 1, cnt + 1);
					arr[y][x] = false;
				}
				else if (flag == true) {
					arr[y][x] = 1;
					func(y, x + 1, cnt + 1);
					arr[y][x] = false;
				}
			}
		}
		flag = true;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 0) zero++;
		}
	}

	func(0,0,0);

	cout << MAX;

}