// 1시간

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct is {
	int y;
	int x;
	bool dir;
	int cnt;
};

int dx[] = { 0, 0, -1, 1,0};
int dy[] = { 1,-1, 0, 0,0};
int ry[] = { -1,-1,0,1,1,0 }; // 수직 일때
int rx[] = { -1,1,1,1,-1,-1 };
int ly[] = { 1,1,1,-1,-1,-1 }; // 수평 일때
int lx[] = { -1,0,1,-1,0,1 };

int N;
char arr[51][51];
bool visited[51][51][2];
pair<int,int> to[3];
pair<int, int> la[3];
is tong;
is last;

bool bfs() {
	// 0 가로 1 세로
	queue<is> q;
	visited[tong.y][tong.x][tong.dir] = true;
	q.push({tong.y,tong.x,tong.dir,0});

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x; 
		bool dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();

		if (y == last.y && x == last.x && dir == last.dir) {
			cout << cnt;
			return true;
		}

		for (int i = 0; i < 5; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (i == 4) { // 회전
				bool flag = false;
				if (dir == 0 && !visited[y][x][1]) { // 수평
					for (int j = 0; j < 6; j++) {
						int ky = y + ly[j];
						int kx = x + lx[j];
						if (arr[ky][kx] == '1' || ky < 0 || ky >= N || kx < 0 || kx >= N) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						visited[y][x][1] = true;
						q.push({ y,x,1,cnt + 1 });
					}
				}
				else if (dir == 1 && !visited[y][x][0]) { // 수평
					for (int j = 0; j < 6; j++) {
						int ky = y + ry[j];
						int kx = x + rx[j];
						if (arr[ky][kx] == '1' || ky < 0 || ky >= N || kx < 0 || kx >= N) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						visited[y][x][0] = true;
						q.push({ y,x,0,cnt + 1 });
					}
				}
			}
			else if (dir == 0 && 1 <= nx && nx < N - 1 && 0 <= ny && ny < N) {// 가로
				if (arr[ny][nx] != '1' && arr[ny][nx - 1] != '1' && arr[ny][nx + 1] != '1' && !visited[ny][nx][dir]) {
					visited[ny][nx][dir] = true;
					q.push({ ny,nx,dir,cnt + 1 });
				}
 			}
			else if (dir == 1 && 0 <= nx && nx < N && 1 <= ny && ny < N -1) {// 세로
				if (arr[ny][nx] != '1' && arr[ny - 1][nx] != '1' && arr[ny + 1][nx] != '1' && !visited[ny][nx][dir]) {
					visited[ny][nx][dir] = true;
					q.push({ ny,nx,dir,cnt + 1 });
				}
			}
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string input;
	int t = 0, e = 0;
	for (int y = 0; y < N; y++) {
		cin >> input;
		for (int x = 0; x < N; x++) {
			arr[y][x] = input[x];
			if (arr[y][x] == 'B') {
				to[t] = { y,x };
				arr[y][x] = '0';
				t++;
			}
			else if (arr[y][x] == 'E') {
				la[e] = { y,x };
				e++;
			}
		}
	}

	if (to[0].first == to[1].first) tong = { to[1].first,to[1].second,0,0 };
	else tong = { to[1].first,to[1].second,1,0 };
	if (la[0].first == la[1].first) last = { la[1].first,la[1].second,0,0};
	else last = { la[1].first,la[1].second,1,0};

	if( bfs() == false) cout << 0;
}