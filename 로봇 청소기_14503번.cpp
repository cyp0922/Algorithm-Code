#include<iostream>
#include<queue>

using namespace std;

int N, M;
//  ºÏ µ¿ ³² ¼­

int map[51][51];
bool visited[51][51];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int dir;
int clean;

void func(int y_, int x_) {
	
	if (!map[y_][x_] && !visited[y_][x_]) {
		visited[y_][x_] = true;
		clean++;
	}

	for (int i = 1; i <=4; i++) {
		int n_dir = dir - i;
		if (n_dir < 0) n_dir = 4 + n_dir;
		
		int n_y = y_ + dy[n_dir];
		int n_x = x_ + dx[n_dir];
		
		if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M) {
			if (map[n_y][n_x] == 0 && !visited[n_y][n_x]) {
				dir = n_dir;
				func(n_y, n_x);
			}
		}
	}

	int n_y = y_ + dy[(dir + 2) % 4];
	int n_x = x_ + dx[(dir + 2) % 4];

	if (n_y < 0 || n_y >= N || n_x < 0 || n_x >= M|| map[n_y][n_x]) {
			cout << clean;
			exit(0);
	}

	else {
		func(n_y, n_x);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	int R, C;
	cin >> N >> M;
	cin >> R >> C >> dir;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	func(R, C);

}