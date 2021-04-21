#include<iostream> 
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int W, H;
char arr[101][101];
bool visited[101][101][4];

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int MIN = 1e9;
pair<int, int> c[2];

struct is {
	int y;
	int x;
	int cnt;
	int dir;
};

struct cmp {
	bool operator()(is a, is b) {
		return a.cnt > b.cnt;
	}
};

void bfs() {

	priority_queue<is, vector<is>, cmp> q;
	q.push({ c[0].first , c[0].second,0 ,5 });

	while (!q.empty()) {

		int y = q.top().y;
		int x = q.top().x;
		int cnt = q.top().cnt;
		int dir = q.top().dir;
		q.pop();

		visited[y][x][dir] = true;

		if (c[1].first == y && c[1].second == x) {
			MIN = min(MIN, cnt);
			continue;
		}

		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W) {
				if (!visited[ny][nx][i] && arr[ny][nx] != '*') {
					if (dir == i || dir == 5) q.push({ ny,nx,cnt,i });
					else if (dir != i) q.push({ ny,nx,cnt + 1, i });
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> W >> H;
	string input;

	int k = 0;
	for (int y = 0; y < H; y++) {
		cin >> input;
		for (int x = 0; x < W; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'C') {
				c[k] = { y,x };
				k++;
			}
		}
	}

	bfs();
	cout << MIN;
}