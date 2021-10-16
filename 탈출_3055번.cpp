#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

char arr[51][51];
bool visited[51][51];
int N, M;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct k {
	int y;
	int x;
	bool kind;
	int dis;
};

queue<k> q;

int bfs() {

	while (!q.empty()) {
		
		int y = q.front().y;
		int x = q.front().x;
		int cmp = q.front().kind;
		int dis = q.front().dis;
		q.pop();

		for (int i = 0; i < 4; i++) {
			
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (cmp == 0) { // 물이면
					if (arr[ny][nx] =='.') {
						visited[ny][nx] = true;
						arr[ny][nx] = '*';
						q.push({ ny,nx,false, 0 });
					}
				}
				else if (cmp == 1) { // 고슴도치
					if (visited[ny][nx] == 0 && arr[ny][nx] == '.') {
						visited[ny][nx] = true;
						q.push({ ny,nx,true, dis + 1});
					}
					else if (!visited[ny][nx] && arr[ny][nx] == 'D') {
						return dis + 1;
					}
				}
				
			}

		}

	}
	return false;

}

int main() {

	cin >> N >> M;
	string input;
	
	vector<pair<int, int>> w;
	vector<pair<int, int>> g;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			arr[i][j] = input[j];
			if (arr[i][j] == '*') {
				w.push_back({ i,j });
				visited[i][j] = true;
			}
			else if (arr[i][j] == 'S') {
				g.push_back({ i,j });
				visited[i][j] = true;
				arr[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < w.size(); i++) {
		q.push({ w[i].first,w[i].second,false, 0 });
	}
	q.push({ g[0].first,g[0].second,true,0 });

	int re = bfs();
	if (re == 0) cout << "KAKTUS";
	else cout << re;

}