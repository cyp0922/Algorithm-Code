#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char arr[12][6];
bool visited[12][6];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool bfs(int cy, int cx) {

	visited[cy][cx] = true;
	queue<pair<int, int>> q;
	q.push({ cy,cx });

	queue<pair<int, int>> store;
	store.push({ cy,cx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= nx && nx < 6 && 0 <= ny && ny < 12) {
				if (!visited[ny][nx] && arr[ny][nx] == arr[cy][cx]) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
					store.push({ ny,nx });
				}
			}
		}
	}

	if (store.size() >= 4) {
		int s = store.size();
		for (int i = 0; i < s; i++) {
			arr[store.front().first][store.front().second] = '.';
			store.pop();
		}
		return true;
	}
	return false;
}

void fall() {
	for (int x = 0; x < 6; x++) {
		int idx = 0;
		for (int y = 0; y < 12; y++) {
			if (arr[idx][x] != '.') idx++;
			else break;
		}
		for (int y = idx; y < 12; y++) {
			if (arr[y][x] != '.') {
				arr[idx][x] = arr[y][x];
				arr[y][x] = '.';
				idx++; 
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int y = 11; y >= 0; y--) {
		for (int x = 0; x < 6; x++) {
			cin >> arr[y][x];
		}
	}
	bool flag = false;
	int num = 0; 
	while (!flag) {
		flag = true;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (arr[y][x] != '.' && !visited[y][x]) {
					if (bfs(y, x)) flag = false;
				}
			}
		}
		fall();
		if (flag == true) {
			cout << num << endl;
			break;
		}
		else num++;
	}
}