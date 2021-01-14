#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool arr[100001];

int N, K, X;
int dx[3] = { 0 ,1,-1 };
/*
struct cmp {
	bool operator()(pair<int, int>a, pair<int, int> b) {
		return a.second > b.second;
	} 
}; 왜 cmp는 안될까 ,,*/ 

int bfs(int x, int c) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
	q.push({ c,x });
	arr[x] = true;

	while (!q.empty()) {

		int cur = q.top().second;
		int cnt = q.top().first;
		dx[0] = cur;
		q.pop();

		if (cur == K) return cnt;

		for (int i = 0; i < 3; i++) {

			int next = cur + dx[i];

			if (next >= 0 && next <= 100000) {
				if (!arr[next]) {
					arr[next] = true;
					if(i==0) q.push({ cnt,next });
					else q.push({ cnt + 1,next });
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

	cout << bfs(X, 0);


}