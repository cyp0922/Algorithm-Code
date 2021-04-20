#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int arr[11];
bool check[11];
bool visited[11];
vector<int> order;
vector<vector<int>> sector;
int MIN = 1e9;

int bfs(int x, int cnt) {

	queue<int> q;
	visited[x] = true;
	q.push({ x });
	int sum = arr[x];

	while (!q.empty()) {

		int y = q.front();
		q.pop();

		for (int i = 0; i < sector[y].size(); i++) {
			int ny = sector[y][i];
			if (check[ny] == cnt && !visited[ny]) {
				visited[ny] = true;
				sum += arr[ny];
				q.push({ ny });
			}
		}
	}
	return sum;
}

void func(int cnt) {

	if (1 <= cnt && cnt <= N / 2) {
		memset(visited, false, sizeof(visited));

		int rsum = 0;
		int bsum = 0;
		for (int i = 0; i < N; i++) {
			if (check[i]) {
				rsum = bfs(i, 1);
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				bsum = bfs(i, 0);
				break;
			}
		}
		int num = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) num++;
		}
		if (num == 0) MIN = min(MIN, abs(rsum - bsum));
	}
	else if (cnt > N / 2) return;

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			func(cnt + 1);
			check[i] = false;
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int k,input;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> input; 
			v.push_back(input - 1);
		}
		sector.push_back(v);
	}

	func(0);

	cout << (MIN == 1e9 ? -1 : MIN);
}