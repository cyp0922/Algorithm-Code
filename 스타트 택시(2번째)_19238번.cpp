#include<iostream> 
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M, F;
int arr[21][21]; 
bool visited[21][21];
struct ta {
	int y;
	int x;
	int fuel;
};
struct is {
	int y;
	int x;
	int fuel; 
	int use;
};
struct ss {
	int sy;
	int sx;
	int ey;
	int ex;
	bool end;
};

ta taxi;
vector<ss> son;
vector<ta> order;

int dx[] = { -1,0,1,0 }; 
int dy[] = { 0,1,0,-1 };

bool cmp(ta a, ta b) {
	if (a.fuel == b.fuel) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.fuel < b.fuel;
}

bool find_bfs() {

	memset(visited, false, sizeof(visited));
	queue<is> q;
	visited[taxi.y][taxi.x] = true; 
	q.push({ taxi.y,taxi.x, taxi.fuel,0 });
	int MIN = 1e9;
	order.clear();

	while (!q.empty()) {
	
		int y = q.front().y;
		int x = q.front().x;
		int feul = q.front().fuel; 
		int use = q.front().use;
		q.pop();

		if (MIN < use) continue;
		else if (taxi.fuel < 0) return 0;
		else if (arr[y][x] >= 2) {
			MIN = min(MIN, use);
			order.push_back({ y,x,feul - use });
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N && !visited[ny][nx] ) {
				if (arr[ny][nx] != 1) {
					visited[ny][nx] = true;
					q.push({ ny,nx,feul,use + 1 });
				}
			}
		}
	}
	return true;
}

bool go_bfs() {

	memset(visited, false, sizeof(visited));
	queue<is> q;
	int e = arr[taxi.y][taxi.x];
	visited[taxi.y][taxi.x] = true;
	q.push({ taxi.y,taxi.x, taxi.fuel,0 });

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int feul = q.front().fuel;
		int use = q.front().use;
		q.pop();

		if (feul - use < 0) {
			return false;
		}
		else if (son[e - 2].ey == y && son[e - 2].ex == x) {
			arr[taxi.y][taxi.x] = 0;
			taxi.y = y;
			taxi.x = x;
			taxi.fuel = feul + use;
			son[e - 2].end = true;
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= N && 1 <= nx && nx <= N && !visited[ny][nx]) {
				if (arr[ny][nx] != 1) {
					visited[ny][nx] = true;
					q.push({ ny,nx,feul,use + 1 });
				}
			}
		}
	}
	return false;
}

int play() {

	while (true) {
		if (find_bfs()) {
			if (order.size() == 0) return -1;
			sort(order.begin(), order.end(), cmp);
			taxi.y = order[0].y;
			taxi.x = order[0].x;
			taxi.fuel = order[0].fuel;

			if (go_bfs()) {
				int num =0;
				for (int i = 0; i < son.size(); i++) {
					if (son[i].end == true) num++;
					else break;
				}
				if (num == son.size()) return taxi.fuel;
			}
			else return -1;
		}
		else return -1;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> F;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}
	int a, b, c, d;
	cin >> a >> b;
	taxi = { a,b ,F };
	int k = 1;
	for (int i = 0; i < M; i++) {
		k++;
		cin >> a >> b >> c >> d;
		arr[a][b] = k;
		son.push_back({ a,b,c,d ,0 });
	}

	cout << play();
}