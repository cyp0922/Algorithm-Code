#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, K;
char arr[101][101];
int visited[101][101];
int check[101];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void print() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cout << arr[y][x];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool bfs(int cy, int cx, int h, int num) {

	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	queue<pair<int, int>> dis;
	q.push({ cy,cx });
	visited[cy][cx] = num;
	bool flag = false;

	if (cy == N) flag = true;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= M) {
				if (arr[ny][nx] == 'x' && !visited[ny][nx]) {
					visited[ny][nx] = num;
					q.push({ ny,nx });
					if (ny == N) flag = true;
				}
				else if (arr[ny][nx] == '.') {
					if (i == 1 && check[nx] < y) check[nx] = y;
				}
			}
		}
	}

	if (flag == false) {

		int MIN = 1e9;

		for (int i = 1; i <= M; i++) {
			if (check[i]) {
				int gap = 0;
				int y = check[i];
				int nx = i;
				while (true) {
					gap++;
					int ny = y + gap;
					if (arr[ny][nx] == 'x' || ny > N) break;
				}
				MIN = min(gap - 1, MIN);
			}
		}

		for (int y = N; y >= 1; y--) {
			for (int x = M; x >= 1; x--) {
				if (visited[y][x] == num) {
					arr[y][x] = '.';
					arr[y + MIN][x] = 'x';
				}
			}
		}
		return true;
	}
	return false;
}

void block(int h, int dir) {

	if (dir == 0) { // Â¦ ¿ÞÂÊ
		int gap = 0;
		int ny = h;
		while (true) {
			int nx = 1 + gap;
			if (nx <= M) {
				if (arr[ny][nx] == 'x') {
					arr[ny][nx] = '.';
					break;
				}
			}
			else break;
			gap++;
		}
	}
	else {
		if (dir == 1) { // È¦ ¿À¸¥ÂÊ
			int gap = 0;
			int ny = h;
			while (true) {
				int nx = M - gap;
				if (nx >= 1) {
					if (arr[ny][nx] == 'x') {
						arr[ny][nx] = '.';
						break;
					}
				}
				else break;
				gap++;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	int num = 1;
	bool flag = true;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (arr[y][x] == 'x' && !visited[y][x]) {
				if (bfs(y, x, h, num)) return;
				num++;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	string input;
	for (int y = 1; y <= N; y++) {
		cin >> input;
		for (int x = 1; x <= M; x++) {
			arr[y][x] = input[x - 1];
		}
	}

	cin >> K;
	int a;
	for (int p = 0; p < K; p++) {
		cin >> a;
		block(N - a + 1, p % 2);
	}
	print();
}

