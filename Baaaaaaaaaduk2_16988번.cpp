// 40Ка
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std; 

int N, M; 
int arr[21][21];
bool visited[21][21];
int MAX = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int bfs(int cy, int cx) {

	queue <pair<int, int>> q;
	visited[cy][cx] = true;
	q.push({cy,cx});
	bool flag = false;
	int K = 1;

	while (!q.empty()) {
		
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {
				if (arr[ny][nx] == 2) {
					visited[ny][nx] = true;
					K++;
					q.push({ny,nx});
				}
				if (arr[ny][nx] == 0) {
					flag = true;
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
	if (flag) return 0;
	return K;
}

void func(int cy, int cx ,int cnt) {
	
	if (cnt == 2) {

		int sum = 0;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (arr[y][x] == 2 && !visited[y][x]) {
					int num = bfs(y, x);
					if (num) {
						sum += num;
						MAX = max(MAX, sum);
					}
				}
			}
		}
		return;
	}

	for (int y = cy; y < N; y++) {
		for (int x = cx; x < M; x++) {
			if (arr[y][x] == 0) {
				arr[y][x] = 1;
				func(y, x + 1, cnt + 1);
				arr[y][x] = 0;
			}
		}
		cx = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	func(0, 0, 0);
	cout << MAX;
}