#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N;
char map[101][101];
char map2[101][101];
bool visited_1[101][101];
bool visited_2[101][101];
int cnt_1 =0 ;
int cnt_2 =0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs_o(int y, int x) {
	
	queue< pair<int, int> > q;
	q.push({ y,x });
	visited_1[y][x] = true;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
				if (map[y][x] == map[n_y][n_x] && !visited_1[n_y][n_x]) {
					visited_1[n_y][n_x] = true ;
					q.push({ n_y,n_x });
				}
			}
		}

	}

	cnt_1 = cnt_1 + 1;
	return;

}

void bfs_x(int y, int x) {

	queue< pair<int, int> > q;
	q.push({ y,x });
	visited_2[y][x] = true;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			if (n_x >= 0 && n_x < N && n_y >=0 && n_y < N) {
				if (map2[y][x] == map2[n_y][n_x] && !visited_2[n_y][n_x]) {
					visited_2[n_y][n_x] = true;
					q.push({ n_y,n_x });
				}
			}
		}

	}

	cnt_2 = cnt_2 + 1;
	return;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string input;

	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < input.size(); x++) {
			map[y][x] = input[x];

			if (input[x] == 'G') {
				map2[y][x] = 'R';
			}
			else map2[y][x] = input[x];
			
		}
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (!visited_1[y][x]) bfs_o(y, x);
			if (!visited_2[y][x]) bfs_x(y, x);
		}
	}

	cout << cnt_1 << " " << cnt_2;

}