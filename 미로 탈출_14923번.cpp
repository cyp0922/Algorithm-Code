#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N, M;
bool arr[1001][1001];
bool visited[1001][1001][2];
int cy, cx, ex, ey;

struct is {
	int y;
	int x;
	int cnt;
	int dis;
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {

	queue<is> q;
	visited[cy][cx][0] = true;
	q.push({ cy,cx, 0,0 });
	
	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt; 
		int dis = q.front().dis; 
		q.pop();

		if (y == ey && x == ex) return dis;
	
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= M) {
				if (arr[ny][nx] == 0 && !visited[ny][nx][cnt]) {
					visited[ny][nx][cnt] = true; 
					q.push({ ny,nx,cnt,dis + 1 });
				}
				else if (arr[ny][nx] == 1 && !visited[ny][nx][cnt + 1] && cnt == 0) {
					visited[ny][nx][cnt + 1] = true;
					q.push({ ny,nx,cnt + 1,dis + 1 });
				}
			}
		}
	}
	return 0;
}


int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	cin >> N >> M;
	cin >> cy >> cx >> ey >> ex;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
		}
	}

	int num = bfs();
	if (num) cout << num;
	else cout << -1;

}