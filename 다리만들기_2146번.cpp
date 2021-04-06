// 40Ка

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int N;
int arr[101][101];
bool visited[101][101];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int MIN = 1e9;

struct is {
	int y;
	int x;
	int num;
};

vector<is> island;

void brige() {

	for (int k = 0; k < island.size(); k++) {
		
		memset(visited, false, sizeof(visited));
		int cy = island[k].y;
		int cx = island[k].x;
		int num = island[k].num;
		bool flag = false;

		queue<pair<int,pair<int, int>>> q;
		q.push({ 0,{ cy,cx } });
		visited[cy][cx] = 0;

		while (!q.empty() && !flag) {

			int cnt = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();

			if (cnt >= MIN) break;

 			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {
					if (arr[ny][nx] == 0) {
						visited[ny][nx] = true;
						q.push({ cnt + 1,{ ny,nx } });
					}
					else if (arr[ny][nx] != num) {
						MIN = min(MIN, cnt);
						flag = true;
						break;
					}
				}
			}
		}
	}
}

void bfs(int cy, int cx, int num) {

	queue<pair<int, int>> q;
	q.push({ cy,cx });
	visited[cy][cx] = true;
	arr[cy][cx] = num;

	while (!q.empty()) {

		int y = q.front().first; 
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx]) {
				if (arr[ny][nx]) {
					visited[ny][nx] = true;
					arr[ny][nx] = num;
					q.push({ ny,nx });
				}
				else if (arr[ny][nx] == false) {
					if (!island.empty()) {
						if (island.back().y == y && island.back().x == x) continue;
					}
					island.push_back({ y,x,num });
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}

	int k = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == 1 && !visited[y][x]) {
				bfs(y, x, k);
				k++;
			}
		}
	}

	brige();
	cout << MIN;

}