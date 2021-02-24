#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int N, Q;
int n;
int arr[65][65];
int q[1001];
int MAX = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool visited[65][65];
void bfs(int y_, int x_) {

	queue<pair<int, int>> q;
	q.push({y_,x_});
	visited[y_][x_] = true; 
	int cnt = 1;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (arr[ny][nx] && !visited[ny][nx]) {
					visited[ny][nx] = true;
					cnt++;
					q.push({ ny,nx });
				}
			}
		}
	}
	
	MAX = max(MAX, cnt);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ �ִ� ĭ 3�� �Ǵ� �� �̻�� ���������� ���� ĭ�� ������ ���� 1�پ���.
	// (r,c)�� ������ ĭ���̴�.
	// �� Q�� ����
	// �����ִ� ������ ��
	// �����ִ� ���� �� ���� ū ����� �����ϴ� ĭ�� ����

	cin >> N >> Q;

 	n = pow(2, N);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < Q; i++) cin >> q[i];

	for (int p = 0; p < Q; p++) {

		// ȸ��
		int cmp[65][65];
		memset(cmp,0, sizeof(cmp));

		int gap = pow(2, q[p]);
		for (int y = 0; y < n; y += gap) {
			for (int x = 0; x < n; x += gap) {
				
				int store[65][65];
				int i = 0; int j = 0;
				for (int b = y; b < y + gap; b++) {
					for (int a = x; a < x + gap; a++) {
						store[j][i] = arr[b][a];
						i++;
					}
					i = 0; 
					j++;
				}

				for (int b = 0; b < gap; b++) {
					for (int a = 0; a < gap; a++) {
						cmp[b+y][a+x] = store[gap - 1 - a][b];
					}
				}
			}
		}
		memcpy(arr, cmp, sizeof(arr));

		// ��´�
		memcpy(cmp, arr, sizeof(cmp));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {

				int cnt = 0;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if (arr[ny][nx]) cnt++;
					}
				}
				if (cnt < 3 && cmp[y][x]) cmp[y][x]--;
			}
		}
		memcpy(arr, cmp, sizeof(arr));

	}

	int sum = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (arr[y][x] && !visited[y][x]) bfs(y, x);
			sum += arr[y][x];
		}
	}

	cout << sum << "\n" << MAX;

}