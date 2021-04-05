#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int N;
int arr[11];
bool visited[11];
bool d_vis[11];
vector<vector<int>> sector;
vector<int> op;

int MIN = 1e9;

bool bfs(int a, bool flag) {

	queue<int> q;
	d_vis[a - 1] = true;
	q.push(a - 1);

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (int i = 0; i < sector[x].size(); i++) {
			int k = sector[x][i] - 1;
			if (visited[k] == flag && !d_vis[k]) {
				d_vis[k] = true;
				q.push(k);
			}
		}
	}

	for (int i = 0; i < op.size(); i++) {
		if (!d_vis[op[i] - 1]) return false;
	}
	return true;

}

void play() {

	int sum1 = 0;
	int sum2 = 0;

	memset(d_vis, false, sizeof(d_vis));
	op.clear();

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			sum1 += arr[i];
			op.push_back(i + 1);
		}
	}
	if (!bfs(op[0], true)) return;

	memset(d_vis, false, sizeof(d_vis));
	op.clear();
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			sum2 += arr[i];
			op.push_back(i + 1);
		}
	}

	if (bfs(op[0], false)) {
		MIN = min(MIN, abs(sum1 - sum2));
	}
}

void func(int k, int cnt) {

	if (0 < cnt && cnt <= N / 2) {
		play();
	}
	else if (cnt > N / 2) return;

	for (int i = k + 1; i < N; i++) {
		visited[i] = true;
		func(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int k, input;
	for (int i = 0; i < N; i++) {
		cin >> k;
		vector<int> v;
		for (int j = 0; j < k; j++) {
			cin >> input;
			v.push_back(input);
		}
		sector.push_back(v);
	}

	func(-1, 0);

	cout << (MIN == 1e9 ? -1 : MIN);

}