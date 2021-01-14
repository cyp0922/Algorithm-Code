#include<iostream>
#include<string>
#include<queue>

using namespace std;

int L, R, C;
char map[31][31][31];
bool visited[31][31][31];

int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int bfs(int z_, int y_, int x_){
	
	queue< pair< pair<int,int>, pair<int,int>> >q;
	q.push({ {0, z_ },{ y_,x_ } });
	visited[z_][y_][x_] = true;

	while (!q.empty()) {

		int time = q.front().first.first;
		int z = q.front().first.second;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {

			int n_z = z + dz[i];
			int n_y = y + dy[i];
			int n_x = x + dx[i];

			if (n_z >= 0 && n_z < L && n_y >= 0 && n_y < R && n_x >= 0 && n_x < C) {

				if (map[n_z][n_y][n_x] == 'E') {
					return time +1;
				}
				if (map[n_z][n_y][n_x] == '.'  && !visited[n_z][n_y][n_x]) {
						visited[n_z][n_y][n_x] = true;
						q.push({ {time + 1, n_z},{n_y,n_x} });
				}
			}
		}

	}

	return -1;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// # 금 , . 비어있는칸, S시작지점, E탈출구

	
	while (true){

		cin >> L >> R >> C;
		
		if (C == 0 && L == 0 && R == 0) break;

		string input;
		int s_x=0, s_y=0, s_z=0;

		// 입력
		for (int z = 0; z < L; z++) {
			for (int y = 0; y < R; y++) {
				cin >> input;
				for (int x = 0; x < C; x++) {
					map[z][y][x] = input[x];
					if (input[x] == 'S') {
						s_x = x;
						s_y = y;
						s_z = z;
					}
				}
			}
		}
		//

		int cnt = bfs(s_z, s_y, s_x);

		if (cnt >= 0) {
			cout << "Escaped in " << cnt << " minute(s)."<< "\n";
		}
		else cout << "Trapped!" << "\n";

		for (int z = 0; z < L; z++) {
			memset(map[z], false, sizeof(map[z]));
			memset(visited[z], false, sizeof(visited[z]));
		}
			

	}


}