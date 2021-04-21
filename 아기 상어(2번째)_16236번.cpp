#include<iostream> 
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N;
int arr[21][21];
bool visited[21][21];

struct sh {
	int y;
	int x;
	int size;
	int eat;
};

struct is {
	int y;
	int x;
	int cnt;
};

bool cmp(is a, is b) {
	if (a.cnt == b.cnt) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.cnt < b.cnt;
}

sh shark;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector<is> order;

int bfs() {

	memset(visited, false, sizeof(visited));
	queue<is> q;
	visited[shark.y][shark.x] = true; 
	q.push({ shark.y,shark.x, 0});
	order.clear();

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (arr[y][x] >= 1) {
			if (arr[y][x] < shark.size) {
				order.push_back({ y,x, cnt });
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N && !visited[ny][nx]) {
				if (arr[ny][nx] <= shark.size) {
					visited[ny][nx] = true;
					q.push({ ny,nx, cnt +1 });
				}
			}
		}
	}

	if (order.size() == 0) return 0;

	if (order.size() > 1)  sort(order.begin(), order.end(), cmp);
	shark.y = order[0].y;
	shark.x = order[0].x;
	shark.eat ++;
	arr[order[0].y][order[0].x] = 0;
	return order[0].cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 9) {
				shark = { y,x,2,0 };
				arr[y][x] = 0;
			}
		}
	}
	
	int time_ = 0;
	while (true) {
		int num = bfs();
		if (num) {
			time_ += num;
			if (shark.eat >= shark.size) {
				shark.eat -= shark.size; 
				shark.size++;
			}
		}
		else break;
	}
	cout << time_;
}