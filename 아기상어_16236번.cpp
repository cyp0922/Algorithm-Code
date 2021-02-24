#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int N;
int map[21][21];
bool visited[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<pair<int, pair<int, int>>> caneat;

typedef struct shark_ {

	int size = 2;
	int eat = 0;
	int y;
	int x;

}shark;

shark s;

bool cmp( pair<int,pair<int,int>> a, pair<int,pair<int,int>> b ) {

	if (a.first == b.first) {

		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		else return a.second.first < b.second.first;
	}
	else return a.first < b.first; 

}

void bfs(int y_,int x_) {

	int MIN = 1e9;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, { y_,x_ } });
	visited[y_][x_] = true;

	while (!q.empty()) {
		
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (cnt > MIN) return;

		for (int i = 0; i < 4; i++) {
		
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {

				if ( map[ny][nx] <= s.size) {

					if ( map[ny][nx] && map[ny][nx] < s.size) {
						caneat.push_back({ cnt+1,{ny,nx} });
						MIN = min(MIN, cnt);
					}

					visited[ny][nx] = true; 
					q.push({ cnt + 1,{ny,nx} });

				}

			}

		}

	}

	return; 
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) s.y = y, s.x = x, map[y][x] = 0;
		}
	}

	int cnt = 0;

	while (true) {

		bfs(s.y,s.x);
		memset(visited, false, sizeof(visited));

		if (caneat.size() == 0) break;

		sort(caneat.begin(), caneat.end(), cmp);

		map[s.y][s.x] = 0;
		s.y = caneat[0].second.first;
		s.x = caneat[0].second.second;
		s.eat++;

		if (s.eat == s.size) {
			s.eat = s.eat - s.size;
			s.size++;
		}
		
		cnt += caneat[0].first;

		caneat.clear();

	}

	cout << cnt;



}