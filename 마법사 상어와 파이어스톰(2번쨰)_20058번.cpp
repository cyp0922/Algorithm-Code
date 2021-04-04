#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int Q, N;
int len;
int arr[65][65];
int cmp[65][65];
int rot[65][65];
int com[1001];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void turn(int L) {


	int gap = pow(2, L);
	memset(cmp, false, sizeof(cmp));
	memset(rot, false, sizeof(rot));
	for (int y = 0; y < len; y += gap) {
		for (int x = 0; x < len; x += gap) {

			// 복사
			int ny = 0; int nx = 0;
			for (int cy = y; cy < y + gap; cy++) {
				nx = 0;
				for (int cx = x; cx < x + gap; cx++) {
					cmp[ny][nx] = arr[cy][cx];
					nx++;
				}
				ny++;
			}

			//회전
			for (int y = 0; y < gap; y++) {
				for (int x = 0; x < gap; x++) {
					rot[y][x] = cmp[gap - 1 - x][y];
				}
			}

			// 대입
			ny = 0; nx = 0;
			for (int cy = y; cy < y + gap; cy++) {
				nx = 0;
				for (int cx = x; cx < x + gap; cx++) {
					arr[cy][cx] = rot[ny][nx];
					nx++;
				}
				ny++;
			}

		}
	}
}

int bfs(int cy, int cx) {

	queue < pair<int, int>> q;
	int cnt = 1;
	q.push({ cy,cx });
	cmp[cy][cx] = true;
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < len && nx >= 0 && nx < len && arr[ny][nx] && !cmp[ny][nx]) {
				cnt++;
				cmp[ny][nx] = true;
				q.push({ ny,nx });
			}
		}

	}

	return cnt;
}

void melt() {

	memcpy(cmp, arr, sizeof(cmp));

	int num = 0;
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {

			if (arr[y][x]) {
				num = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];

					if (ny >= 0 && ny < len && nx >= 0 && nx < len && arr[ny][nx]) num++;
				}

				if (num < 3) cmp[y][x]--;
			}
		}
	}

	memcpy(arr, cmp, sizeof(arr));
}

void solve() {

	for (int p = 0; p < Q; p++) {
		turn(com[p]);
		melt();
	}


	int sum = 0;
	int MAX = 0;
	memset(cmp, false, sizeof(cmp));
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			if (arr[y][x] && !cmp[y][x]) MAX = max(MAX, bfs(y, x));
			if (arr[y][x]) sum += arr[y][x];
		}
	}

	cout << sum << "\n" << MAX;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> Q;

	len = pow(2, N);
	for (int y = 0; y < len; y++) {
		for (int x = 0; x < len; x++) {
			cin >> arr[y][x];
		}
	}
	for (int i = 0; i < Q; i++) cin >> com[i];

	solve();
}