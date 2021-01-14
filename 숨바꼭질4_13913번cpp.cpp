#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int store[100002];
bool arr[100002];
vector<int> s;

int N, K, X;
int dx[3] = { 1,-1,0 };

int bfs(int x, int c) {

	queue<pair<int, int>> q;
	q.push({ x,c });
	arr[x] = true;
	store[x] = -1;

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		dx[2] = cur;
		q.pop();

		if (cur == K) {
		
			int a = cur;
			s.push_back(cur);
			while (true) {

				if (store[a] == -1) break;

				s.push_back(store[a]);
				a = store[a];
			}

			return cnt;
		
		}

		for (int i = 0; i < 3; i++) {

			int next = cur + dx[i];

			if (next >= 0 && next <= 100000) {
				if (!arr[next]) {
					arr[next] = true;
					store[next] = cur;
					q.push({ next,cnt + 1 });
				}
			}


		}

	}

	return 0;



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> X >> K;

	cout << bfs(X, 0) << endl;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i] << " ";
	}


}