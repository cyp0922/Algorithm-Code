#include<iostream>
#include<queue>
using namespace std;

int x, k;
bool arr[100001];
int MIN = 1e9;
int num = 0;
int di[] = { -1,1,0 };

void bfs() {

	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x,0 });
	arr[x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		di[2] = y;
		arr[y] = true;

		if (MIN < cnt) return;

		for (int i = 0; i < 3; i++) {
			int ny = y + di[i];

			if (ny == k && cnt + 1 <= MIN) {
				MIN = cnt + 1;
				num++;
				continue;
			}

			if (ny >= 0 && ny <= 100000) {
				if (!arr[ny]) {
					q.push({ ny,cnt + 1 });
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> x >> k;

	if (x == k) cout << "0\n1";
	else {
		bfs();
		cout << MIN << "\n" << num;
	}
}