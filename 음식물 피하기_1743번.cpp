#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int M, N, K;
bool arr[101][101];
bool visited[101][101];
int MAX = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void bfs(int y_, int x_) {

	queue<pair<int,int>> q;
	q.push({ y_, x_ });
	visited[y_][x_] = true;
	int cnt = 1;
	
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
				if (!visited[ny][nx] && arr[ny][nx]) {
					visited[ny][nx] = true;
					cnt++;
					q.push({ny,nx});
				}
			}
		}

	}

	MAX = max(MAX, cnt);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		arr[y][x] = true;
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (arr[y][x] && !visited[y][x]) {
				bfs(y,x);
			}
 		}
	}


	cout << MAX;

}