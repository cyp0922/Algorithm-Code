// 18Ка

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std; 

int N, M;
int arr[102][102];
bool visited[102][102];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };


int bfs(int cy, int cx) {

	visited[cy][cx] = true; 
	priority_queue< pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
	q.push({ 0,{ cy,cx } });

	while (!q.empty()) {

		int cnt = q.top().first;
		int y = q.top().second.first;
		int x = q.top().second.second;
		q.pop();

		if (y == N && x == M) return cnt;
			
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (arr[ny][nx]) q.push({ cnt + 1,{ny,nx} });
				else if(!arr[ny][nx]) q.push({ cnt,{ny,nx} });
			}
		}
	}
}

int main() {

	scanf("%d %d", &M, &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}

	cout << bfs(1, 1);
}