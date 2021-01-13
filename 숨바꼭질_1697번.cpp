#include<iostream>
#include<queue>

using namespace std;

bool arr[100002];

int N, K, X;
int dx[3] = { 1,-1,0 };

int bfs(int x,int c) {
	
	queue<pair<int, int>> q;
	q.push({ x,c });
	arr[x] = true; 

	while (!q.empty()) {
		
		int cur = q.front().first;
		int cnt = q.front().second;
		dx[2] = cur;
		q.pop();

		if (cur == K) return cnt;
		
		for (int i = 0; i < 3; i++) {
			
			int next = cur + dx[i];

			if (next >= 0 && next <= 100000) {
				if (!arr[next]) {
					arr[next] = true;
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

	cout << bfs(X,0);


}