#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int N,Q;
int arr[65][65];
int cmp[65][65];
bool visited[65][65];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct ss {
	int y;
	int x;
};

void turn(int range) {

	for (int y = 0; y < N; y+= range) {
		for (int x = 0; x < N; x+= range) {

			for (int cy = 0; cy < range; cy++) {
				for (int cx = 0; cx < range; cx++) {
					cmp[y + cy][x + cx] = arr[y + range - 1 - cx][x + cy];
				}
			}
		}
	}
	memcpy(arr, cmp, sizeof(arr));
}

int bfs(int cy, int cx) {

	queue<ss> q;
	visited[cy][cx] = true; 
	q.push({ cy,cx });
	int s = 0;

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		s++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && arr[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
	return s;
}

void melt() {

	memcpy(cmp, arr, sizeof(cmp));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					if (arr[ny][nx]) cnt++;
				}
			}
			if (cnt < 3 && arr[y][x]) cmp[y][x]--;
		}
	}
	memcpy(arr, cmp, sizeof(cmp));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int temp;
	cin >> temp >> Q;

	N = pow(2, temp);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}

	int L;
	for (int p = 0; p < Q; p++) {
		cin >> L;
		turn(pow(2, L));
		melt();
	}

	int sum = 0;
	int MAX = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visited[y][x] && arr[y][x]) {
				MAX = max(MAX, bfs(y, x));
			}
			sum += arr[y][x];
		}
	}
	cout << sum << "\n" << MAX;
}
