#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int N, Q;
int M;
int order[1001];
int arr[65][65];
int cmp[65][65];
bool visited[65][65];
int MAX = 0;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

struct is {
	int y;
	int x; 
	int cnt;
};


void bfs(int cy, int cx) {

	queue<is> q;
	visited[cy][cx] = true;
	q.push({ cy,cx,0 });
	int sum = 1;

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < M && 0 <= nx && nx < M && !visited[ny][nx]) {
				if (arr[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx,cnt + 1 });
					sum++;
				}
			}
		}
	}
	MAX = max(MAX, sum);
}

void play() {

	for (int q = 0; q < Q; q++) {
		
		int gap = pow(2, order[q]);

		for (int y = 0; y < M; y += gap) {
			for (int x = 0; x < M; x += gap) {
				memset(cmp, false, sizeof(cmp)); 
				
				
				for (int cy = 0; cy < gap; cy++) {
					for (int cx = 0; cx < gap; cx++) {
						cmp[cy][cx] = arr[gap - 1 - cx + y][cy + x];
					}
				}

				for (int cy = 0; cy < gap; cy++) {
					for (int cx = 0; cx < gap; cx++) {
						arr[y + cy][x + cx] = cmp[cy][cx];
					}
				}

			}
		}

		memset(cmp, false, sizeof(cmp));
		memcpy(cmp, arr, sizeof(cmp));
		for (int y = 0; y < M; y++) {
			for (int x = 0; x < M; x++) {
				int num = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (0 <= ny && ny < M && 0 <= nx && nx < M) {
						if (arr[ny][nx]) num++;
					}
				}

				if (num < 3) {
					if (cmp[y][x]) cmp[y][x] --;
				}
			}
		}
		memcpy(arr, cmp, sizeof(cmp));
	}

	int cnt = 0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < M; x++) {

			if (arr[y][x]) cnt += arr[y][x];

			if(arr[y][x] && !visited[y][x]) bfs(y,x);
		}
	}
	cout << cnt << "\n" << MAX << endl;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> Q;
	 
	M = pow(2, N);
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}
	for (int i = 0; i < Q; i++) cin >> order[i]; 

	play();
}