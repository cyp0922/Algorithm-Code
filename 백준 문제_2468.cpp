#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N;
int map[101][101];
int visited[101][101];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int max(int a, int b) {
	return a > b ? a : b;
}

void bfs(int y_, int x_,int k)
{
	queue<pair<int, int>> q;
	visited[y_][x_] = true;
	q.push({ y_,x_ });

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < N; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
				if (!visited[n_y][n_x] && map[n_y][n_x] > k) {
					visited[n_y][n_x] = true;
					q.push({n_y,n_x});
				}
			}
		}

	}
	
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> N;

	int w_s = 987654321;
	int w_b = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] < w_s) w_s = map[y][x]; // ³·Àº ´ë·ú
			if (map[y][x] > w_b)  w_b = map[y][x]; // ³ôÀº ´ë·ú
		}
	}


	int MAX = 1;

	for (int k = w_s; k < w_b; k++) { // ¹°¼öÀ§

		int num = 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visited[y][x] && map[y][x] >k ) {
					bfs(y, x, k);
					num++;
				}
			}
		}

		MAX = max(MAX, num);
		memset(visited, false, sizeof(visited));

	}

	cout << MAX;

}