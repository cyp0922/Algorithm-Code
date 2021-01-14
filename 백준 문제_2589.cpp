#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int H, W;
char map[51][51];
char remap[51][51];
int visited[51][51];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int MAX = 0;

void bfs(int y,int x){

	queue< pair<int, int> > q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int cnt = 0;

		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			
			if (n_x >= 0 && n_x < W && n_y >= 0 && n_y < H) {
				
				if (map[n_y][n_x] == map[y][x] && !visited[n_y][n_x]) {
					visited[n_y][n_x] = visited[y][x] + 1;
					MAX = max(MAX, visited[n_y][n_x]);
					q.push({ n_y,n_x });
				}
			}
		}

	}
	
}


int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	cin >> H >> W;

	string input;

	for (int y = 0; y < H; y++) {
		cin >> input;
		for (int x = 0; x < W; x++) {
			map[y][x] = input[x];
		}
	}

	int cmp = 0;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == 'L') {
				bfs(y, x);
				cmp = max(MAX, cmp);
				memset(visited, false, sizeof(visited));

			}
		}
	}

	cout << MAX-1;

}