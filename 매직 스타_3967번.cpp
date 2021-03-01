#include<iostream>
#include<vector>
using namespace std;

char map[6][10];
vector<pair<int, int>> v;
bool visited[13];

void dfs(int cnt) {

	if (cnt == v.size()) {

		if (map[0][4] + map[1][3] + map[2][2] + map[3][1] - 4 * ('A' - 1) != 26) return;
		if (map[0][4] + map[1][5] + map[2][6] + map[3][7] - 4 * ('A' - 1) != 26) return;
		if (map[1][1] + map[1][3] + map[1][5] + map[1][7] - 4 * ('A' - 1) != 26) return;
		if (map[3][1] + map[3][3] + map[3][5] + map[3][7] - 4 * ('A' - 1) != 26) return;
		if (map[1][1] + map[2][2] + map[3][3] + map[4][4] - 4 * ('A' - 1) != 26) return;
		if (map[1][7] + map[2][6] + map[3][5] + map[4][4] - 4 * ('A' - 1) != 26) return;

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 9; x++) {
				cout << map[y][x];
			}
			cout << endl;
		}
		exit(0);
	}

	for (int i = 0; i < 12; i++) {
		if (!visited[i]) {
			visited[i] = true;
			map[v[cnt].first][v[cnt].second] = 'A' + i;
			dfs(cnt + 1);
			visited[i] = false;
			map[v[cnt].first][v[cnt].second] = 'x';
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;

	for (int y = 0; y < 5; y++) {

		cin >> input;
		for (int x = 0; x < 9; x++) {

			map[y][x] = input[x];
			if (input[x] == 'x') v.push_back({ y,x });
			if (input[x] >= 'A' && input[x] <= 'L') visited[input[x] - 'A'] = true;

		}
	}

	dfs(0);

}