#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K;
int arr[1001][1001];
bool visited[1001][1001][2][11];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 }; 
int MIN = 2e9; 

struct is {
	int y;
	int x;
	int cnt;
	int dis;
	bool day;
};

void bfs() {

	queue<is> q;
	visited[1][1][0][0] = true;
	q.push({ 1,1,0,1,0 });

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int dis = q.front().dis; 
		bool day = q.front().day;
		q.pop();

		if (y == N && x == M) {
			MIN = min(dis, MIN);
			continue;
		}

		if (!visited[y][x][!day][cnt]) {
			visited[y][x][!day][cnt] = true; 
			q.push({ y,x,cnt,dis + 1,!day });
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= M ){
				if (!visited[ny][nx][!day][cnt] && arr[ny][nx] == 0) {
					visited[ny][nx][!day][cnt] = true;
					q.push({ ny,nx,cnt,dis + 1,!day });
				}
				else if (!visited[ny][nx][!day][cnt + 1] && day == 0 && arr[ny][nx] == 1 && cnt < K) {
					visited[ny][nx][!day][cnt+1] = true;
					q.push({ ny,nx,cnt + 1,dis + 1,!day });
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}

	bfs();
	cout << (MIN == 2e9 ? -1 : MIN);
}