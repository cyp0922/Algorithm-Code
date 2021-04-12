#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct is {
	int cnt;
	int end;
};

int N, M;
char arr[21][21];
int num[21][21];
bool visited[21][21];
bool check[11];
int num_ = 0;
int MIN = 1e9;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

vector<pair<int, int>> start;
vector <is> clean[11];

void start_bfs(int cy, int cx) {

	memset(visited, false, sizeof(visited));
	queue < pair<int, pair<int, int>>> q;
	visited[cy][cx] = true;
	q.push({ 0,{cy,cx} });

	while (!q.empty()) {
		
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (arr[ny][nx] == '.' || arr[ny][nx] == 'o') q.push({ cnt + 1,{ ny,nx } });
				else if (arr[ny][nx] == '*') {
					start.push_back({ cnt + 1,num[ny][nx] });
					q.push({ cnt + 1,{ ny,nx } });
				}
			}
		}
	}
}

void bfs(int cy, int cx) {

	memset(visited, false, sizeof(visited));
	queue < pair<int, pair<int, int>>> q;
	visited[cy][cx] = true;
	q.push({ 0,{cy,cx} });

	while (!q.empty()) {

		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) {

				visited[ny][nx] = true;
				if (arr[ny][nx] == '.' || arr[ny][nx] == 'o') q.push({ cnt + 1,{ ny,nx } });
				else if (arr[ny][nx] == '*') {
					clean[num[cy][cx]].push_back({ cnt + 1,num[ny][nx] });
					q.push({ cnt + 1,{ ny,nx } });
				}
			}
		}
	}
}

void func(int x, int cnt, int sum) {

	if (cnt == num_) {

		for (int i = 1; i <= num_; i++) {
			if (!check[i]) return;
		}
		MIN = min(MIN, sum);
		return;
	}

	for (int i = 0; i < clean[x].size(); i++) {
		if (!check[clean[x][i].end]) {
			check[clean[x][i].end] = true;
			func(clean[x][i].end, cnt + 1, sum + clean[x][i].cnt);
			check[clean[x][i].end] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		
		memset(check, false, sizeof(check));
		memset(num, false, sizeof(num));
		MIN = 1e9;
		num_ = 0;
		start.clear();
		for (int i = 1; i <= 10; i++) clean[i].clear();

		string input;
		cin >> M >> N;
		
		if (M == 0 && N == 0) break;
 		
		for (int y = 0; y < N; y++) {
			cin >> input;
			for (int x = 0; x < M; x++) {
				arr[y][x] = input[x];
				if (arr[y][x] == '*') {
					num_++;
					num[y][x] = num_;
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (arr[y][x] == 'o') start_bfs(y, x);
				else if (arr[y][x] == '*') bfs(y, x);
			}
		}

		for (int i = 0; i < start.size(); i++) {
			check[start[i].second] = true;
			func(start[i].second, 1, start[i].first);
			check[start[i].second] = false;
		}
		cout << (MIN == 1e9 ? -1 : MIN) << endl;
	}
}