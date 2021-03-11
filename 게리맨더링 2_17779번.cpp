#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int N;
int arr[22][22];
int cmp[22][22];
bool visited[22][22];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int MIN = 1e9;

int bfs(int cy, int cx, int num) {

	int sum = arr[cy][cx];
	queue<pair<int, int>> q;
	visited[cy][cx] = true;
	q.push({ cy,cx });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[ny][nx]) {
				if (cmp[ny][nx] == 0) {
					sum += arr[ny][nx];
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
				if (num == 5 && cmp[ny][nx] == num) {
					q.push({ ny,nx });
					sum += arr[ny][nx];
					visited[ny][nx] = true;
				}
				else if (cmp[ny][nx] == num) {
					sum += arr[ny][nx];
					visited[ny][nx] = true;
				}
			}
		}
	}

	return sum;

}

void func(int ky, int kx, int d1, int d2) {

	if (d1 != 0 && d2 != 0) {

		memset(cmp, false, sizeof(cmp));
		memset(visited, false, sizeof(visited));

		// 왼쪽 상단
		int y = ky;
		for (int x = kx; x <= kx + d1; x++) {
			cmp[y][x] = 5;
			y++;
		}
		for (int i = 0; y + i <= N; i++) cmp[y + i][kx + d1] = 4;

		// 왼쪽 하단

		for (int i = 1; kx - i >= 1; i++) cmp[ky][kx - i] = 3;

		y = ky;
		for (int x = kx; x <= kx + d2; x++) {
			cmp[y][x] = 5;
			y--;
		}
		for (int i = 0; y - i >= 1; i++) cmp[y - i][kx + d2] = 1;

		// 오른쪽 하단
		y = ky - d2;
		for (int x = kx + d2; x <= kx + d1 + d2; x++) {
			cmp[y][x] = 5;
			y++;
		}

		// 왼쪽 상단
		y = ky + d1;
		for (int x = kx + d1; x <= kx + d1 + d2; x++) {
			cmp[y][x] = 5;
			y--;
		}
		for (int i = 1; kx + d1 + d2 + i <= N; i++) cmp[y + 1][kx + d1 + d2 + i] = 2;

		int MB = 0;
		int SB = 1e9;

		int s1 = bfs(1, 1, 1);
		int s2 = bfs(1, N, 2);
		int s3 = bfs(N, 1, 3);
		int s4 = bfs(N, N, 4);
		int s5 = bfs(ky, kx, 5);
		MB = max(max(max(max(max(s1, s2), s3), s4), s5), MB);
		SB = min(min(min(min(min(s1, s2), s3), s4), s5), SB);

		MIN = min(MIN, abs(MB - SB));

		return;
	}

	for (int kd2 = 1; ky - kd2 >= 1; kd2++) {
		for (int kd1 = 1; kx + kd2 + kd1 <= N && ky + kd1 <= N; kd1++) {
			func(ky, kx, kd1, kd2);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	for (int ky = 2; ky <= N - 1; ky++) {
		for (int kx = 1; kx <= N - 2; kx++) {
			func(ky, kx, 0, 0);
		}
	}

	cout << MIN;

}