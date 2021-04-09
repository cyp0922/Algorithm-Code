#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
bool vland[101];
bool land[101];
bool check[7];
int num = 1;
int MIN = 1e9;
queue<pair<int, pair<int, int>>> store;
vector<int> order;

struct is {
	int start;
	int end;
	int dis;
};
vector<is> island;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void bfs(int cy, int cx) {

	queue<pair<int, int>> q;
	visited[cy][cx] = true;
	q.push({ cy,cx });
	arr[cy][cx] = num;

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !visited[ny][nx]) {
				if (arr[ny][nx]) {
					arr[ny][nx] = num;
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
				else if (arr[ny][nx] == 0) store.push({ i,{ y,x } });
			}
		}
	}
}

void make_brige() {

	int size_ = store.size();
	for (int k = 0; k < size_; k++) {

		int dir = store.front().first;
		int y = store.front().second.first;
		int x = store.front().second.second;
		int cnt = arr[y][x];
		store.pop();

		int ky, kx;
		int gap = 1;
		while (true) {
			ky = y + gap * dy[dir];
			kx = x + gap * dx[dir];
			if (0 <= ky && ky < N && 0 <= kx && kx < M) {
				if (arr[ky][kx] == cnt) break;
				if (arr[ky][kx] != 0 && cnt != arr[ky][kx]) {
					if (gap - 1 > 1) island.push_back({ cnt,arr[ky][kx] ,gap - 1 });
					break;
				}
			}
			else break;
			gap++;
		}
	}
}

bool island_bfs() {

	queue<pair<int,int>> q;
	int k = island[order[0]].start;
	for (int i = 0; i < order.size(); i++) {
		if (island[order[i]].start == k) {
			q.push({ order[i],island[order[i]].end });
			check[island[order[i]].end] = true;
		}
	}
	check[k] = true;

	while (!q.empty()) {
		
		int number = q.front().first;
		int y = q.front().second;
		q.pop();
		vland[number] = true;

		for (int i = 0; i < island.size(); i++) {

			int s = island[i].start;
			int e = island[i].end;
			if (land[i] && !vland[i] && s == y) {
				check[e] = true;
				q.push({ i,e });
			}
		}
	}

	for (int i = 1; i <= num - 1; i++) {
		if (!check[i]) return false;
	}
	for (int i = 0; i < order.size(); i++) {
		if (!vland[order[i]]) return false;
	}

	return true;
}

void func(int x, int cnt, int sum) {

	if (cnt == num - 2) {
		memset(vland, false, sizeof(vland));
		memset(check, false, sizeof(check));

		if (island_bfs()) MIN = min(MIN, sum);
		return;
	}

	for (int i = x + 1; i < island.size(); i++) {
		land[i] = true;
		order.push_back(i);
		func(i, cnt + 1, sum + island[i].dis);
		order.pop_back();
		land[i] = false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] && !visited[y][x]) {
				bfs(y, x);
				num++;
			}
		}
	}
	make_brige();
	func(-1, 0, 0);
	cout << (MIN == 1e9 ? -1 : MIN);
}