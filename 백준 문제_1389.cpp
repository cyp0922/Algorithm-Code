#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std; 

vector<vector<int>> F(101);
int visited[101];
int N, M;

int bfs(int a) {

	queue<pair<int,int>> q;
	visited[a] = -1;
	q.push({ a,0 });

	while (!q.empty()) {
		
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < F[x].size(); i++) {
			if (visited[F[x][i]] == 0) {
				visited[F[x][i]] = cnt + 1;
				q.push({ F[x][i] , cnt + 1 });
			}
		}
	}

	int sum = 1; // 초기 방문 부분이 -1이므로

	for (int i = 1; i <=N; i++) {
		sum += visited[i];
	}

	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		F[a].push_back(b);
		F[b].push_back(a);
	}

	pair<int, int> small;
	small.first = 0;
	small.second = 987654321;

	for (int i = 1; i <= N; i++)
	{
		int cmp = bfs(i);
		small.first = cmp < small.second ? i : small.first;
		small.second = cmp < small.second ? cmp : small.second;
		memset(visited, false, sizeof(visited));
	}

	cout << small.first;

}