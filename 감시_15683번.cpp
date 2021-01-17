#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int dx[] = { -1,0,1,0 }; //аб го ©Л ╩С
int dy[] = { 0,1,0,-1 };

int N, M;
int map[9][9];
int cmp[9][9][9];

int MAX = 0;

vector < pair<int, pair<int, int>>> store;

int bfs(int page, int temp, int dir) {

	int y = store[page - 1].second.first;
	int x = store[page - 1].second.second;

	int count = 0;
	int jump = 0;
	int range= 0;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			cmp[page][j][i] = cmp[page - 1][j][i];
		}
	}

	if (temp == 1) {
		range = 0;
		jump = 1;
	}
	else if (temp == 2)
	{
		range = 2;
		jump = 2;
	}
	else if (temp == 3) {
		range = 1;
		jump = 1;
	}
	else if (temp == 4) {
		range = 2;
		jump = 1;
	}
	else if (temp == 5) {
		range = 3;
		jump = 1;
	}

	for (int i = 0; i <= range; i += jump) {
		int nx = x + dx[(dir + i) % 4];
		int ny = y + dy[(dir + i) % 4];

		while (true) {

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
				break;
			}
			if (cmp[page][ny][nx] == 6) {
				break;
			}

			if (cmp[page][ny][nx] == 0) {
				count++;
				cmp[page][ny][nx] = 9;
			}

			nx += dx[(dir + i) % 4];
			ny += dy[(dir + i) % 4];
		}
	}

	return count;


}

void func(int c, int cnt) {

	if (c == store.size() + 1) {
		MAX = max(MAX, cnt);
		return;
	}

	int temp = store[c - 1].first;
	int y = store[c - 1].second.first;
	int x = store[c - 1].second.second;

	if (temp == 1 || temp == 3 || temp == 4) {
		for (int i = 0; i < 4; i++) {
			func(c + 1, cnt + bfs(c, temp, i));
		}
	}
	else if (temp == 2) {
		for (int i = 0; i < 2; i++) {
			func(c + 1, cnt + bfs(c, temp, i));
		}
	}
	else if (temp == 5) {
		func(c + 1, cnt + bfs(c, temp, 0));
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			cmp[0][y][x] = map[y][x];
		}
	}

	int block = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int temp = map[y][x];
			if (temp >= 1 && temp <= 5) {
				store.push_back({ temp,{y,x} });
			}
			if (temp == 0) block++;
		}
	}

	func(1,0);

	cout << block - MAX;
}