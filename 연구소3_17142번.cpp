#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[11][11];
int cmp[11][11];
int visited[11][11];

vector<pair<int,int>> b;
queue<pair<int,pair<int, int>>> q;
vector<int> f;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool visited_f[11];

int all_cnt = 0;
int zero_cnt = 0;

int N,M;
int MIN = 1e9;

int bfs() {

	int cnt = 0;

	while (!q.empty()) {
		int time = q.front().first;
		int y = q.front().second.first; 
		int x = q.front().second.second;
		if(arr[y][x] != 2) cnt = max(cnt, time);

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny >= 0 && ny < N && nx >= 0 && nx < N && arr[ny][nx] != 1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ time + 1,{ny,nx} });
			}
		}


	}

	return cnt; //시간;
}

void func(int x) {
	
	if (f.size() == M) {
		all_cnt++;

		memset(visited, false, sizeof(visited));
		for (int i = 0; i < f.size(); i++) {
			q.push({ 0,{ b[f[i]].first,b[f[i]].second } });
			visited[b[f[i]].first][b[f[i]].second] = true;
		}

		int temp = bfs();
		int zero = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if(arr[y][x] == 0 && !visited[y][x]) zero++;
			}
		}

		if (zero == 0) MIN = min(temp, MIN);
		else zero_cnt++;

		return;
	}


	for (int i = x; i < b.size(); i++) {
		if (!visited_f[i]) {
			visited_f[i] = true;
			f.push_back(i);
			func(i + 1);
			f.pop_back();
			visited_f[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// 연구소는 빈칸,벽,바이러스
	// 벽은 칸 하나를 가득 차지
	// 활성바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다 .
	// 0 빈칸 1 벽 2 바이러스 위치

	cin >> N >> M;

	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 2) {
				b.push_back({ y,x });
			}
		}
	}

	func(0);

	if (all_cnt == zero_cnt) cout << "-1";
	else  cout << MIN;
}