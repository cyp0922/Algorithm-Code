#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

char arr[6][6];
bool check[6][6];
bool visited[6][6];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
vector<pair<int, int>> store;
int num = 0;
vector<pair<int, int >> v;

bool bfs(int cy, int cx) {
	memset(visited, false, sizeof(visited));
	int sum = 1;
	visited[cy][cx] = true;
	queue<pair<int, int>> q;
	q.push({ cy,cx });
	while (!q.empty()) {
		
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
				if (!visited[ny][nx] && check[ny][nx]) {
					q.push({ ny,nx });
					visited[ny][nx] = true;
					sum++;
				}
			}
		}
	}

	if (sum == 7) return true;
	else return false;

}

void func2(int cy, int cx, int cnt) {

	if (cnt == 7) {
		if (bfs(store[0].first, store[0].second)) num++;
		return;
	}

	for (int y = cy; y < 5; y++) {
		for (int x = cx; x < 5; x++) {
			if (arr[y][x] != 'S') {
				check[y][x] = true;
				store.push_back({ y,x });
				func2(y, x + 1, cnt + 1);
				store.pop_back();
				check[y][x] = false;
			}
		}
		cx = 0;
	}
}

void func1(int cnt, int x) {

	if (cnt >= 4) {
		func2(0, 0, cnt);
	}

	for (int i = x; i < v.size(); i++) {
		check[v[i].first][v[i].second] = true; 
		store.push_back({ v[i].first,v[i].second });
		func1(cnt + 1, i + 1);
		store.pop_back();
		check[v[i].first][v[i].second] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	for (int y = 0; y < 5; y++) {
		cin >> input;
		for (int x = 0; x < 5; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'S') v.push_back({ y,x });
		}
	}

	func1(0, 0);
	cout << num;
}