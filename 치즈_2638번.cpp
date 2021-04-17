#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M; 
int arr[101][101];
bool visited[101][101];
bool check[101][101];

int dx[] = { -1,0,1,0 }; 
int dy[] = { 0,-1,0,1 };

void bfs_out(int cy, int cx, int num) {

	queue<pair<int, int>> q;
	visited[cy][cx] = true; 
	q.push({ cy,cx });
	arr[cy][cx] = num; 

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		int k = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i]; 
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (arr[ny][nx] == 0 || arr[ny][nx] == 2) {
					if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						arr[ny][nx] = num;
						q.push({ ny,nx });
					}
				}
				else k++;
			}
		}
		if (k == 4) arr[y][x] = 2;
	}
}

bool bfs_melt (int cy, int cx) {

	queue<pair<int, int>> q;
	queue<pair<int, int>> melt;
	visited[cy][cx] = true;
	q.push({ cy,cx });
	int sum = 1;
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int k = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (arr[ny][nx] == 1) {
					if (!visited[ny][nx]) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
						sum++;
					}
				}
				else if(arr[ny][nx] == 0) k++;
			}
		}
		if (k >= 2) melt.push({ y,x });
	}

	int ss = melt.size();
	for (int i = 0; i < ss; i++) {
		arr[melt.front().first][melt.front().second] = 0;
		melt.pop();
	}

	if (sum == ss) return true;
	else return false; 
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

	int time_ = 0;

	while (true) {

		memset(visited, false, sizeof(visited));
		time_++;

		for (int y = 0; y < N; y += N - 1) {
			for (int x = 0; x < M; x++) {
				if (!visited[y][x] && arr[y][x] == 0) {
					bfs_out(y, x, 0);
				}
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x += M - 1) {
				if (!visited[y][x] && arr[y][x] == 0) {
					bfs_out(y, x, 0);
				}
			}
		}
		for (int y = 1; y < N - 1; y++) {
			for (int x = 1; x < M - 1; x++) {
				if (!visited[y][x] && (arr[y][x] == 2 || arr[y][x] == 0)) {
					bfs_out(y, x, 2);
				}
			}
		}
		int a = 0;
		int b = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (!visited[y][x] && arr[y][x] == 1) {
					a++;
					if (bfs_melt(y, x)) b++;
				}
			}
		}

		if (a == b) break;
	}
	cout << time_;
}