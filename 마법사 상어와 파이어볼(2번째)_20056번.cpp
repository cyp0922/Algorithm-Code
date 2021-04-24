#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct is {
	int y;
	int x;
	int m;
	int s; 
	int d;
};

struct ma {
	int cnt;
	int m;
	int s;
	int ds;
	int d;
};

vector<is> fire;
ma arr[51][51];

int dx[] = { 0,1,1,1,0,-1,-1,-1 }; 
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int N, M, K;

int play() {

	for (int t = 1; t <= K; t++) {

		memset(arr, false, sizeof(arr));
		int ss = fire.size();

		for (int i = ss -1 ; i >= 0; i--) {

			int y = fire[i].y;
			int x = fire[i].x;
			int m = fire[i].m;
			int s = fire[i].s;
			int d = fire[i].d;
			int ny; int nx;
			for (int i = 0; i < s % N; i++) {
				ny = y + dy[d];
				nx = x + dx[d];
				if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
					y = ny;
					x = nx;
				}
				y = ny;
				x = nx;
				if (ny > N) y = 1;
				if (nx > N) x = 1;
				if (nx < 1) x = N;
				if (ny < 1) y = N;
			}

			arr[y][x].cnt++;
			arr[y][x].m += m;
			arr[y][x].s += s;
			if (arr[y][x].cnt == 1) {
				arr[y][x].d = d;
				arr[y][x].ds = 1;
			}
			if (arr[y][x].cnt > 1) {
				if (arr[y][x].d % 2 ==  d % 2) arr[y][x].ds += 1;
				else arr[y][x].ds += 0;
			}
			fire.pop_back();
		}

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (arr[y][x].cnt == 1) fire.push_back({ y,x,arr[y][x].m, arr[y][x].s,arr[y][x].d });
				else if (arr[y][x].cnt > 1) {
					
					int mass = arr[y][x].m / 5;
					if (mass == 0) continue;

					int speed = arr[y][x].s / arr[y][x].cnt;
					if ( arr[y][x].ds % arr[y][x].cnt == 0) {
						for (int i = 0; i < 8; i += 2) {
							fire.push_back({ y,x,mass,speed,i });
						}
					}
					else {
						for (int i = 1; i < 8; i += 2) {
							fire.push_back({ y,x,mass,speed,i });
						}
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < fire.size(); i++) {
		sum += fire[i].m;
	}
	return  sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	int y, x, m, s, d;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> m >> s >> d;
		fire.push_back({ y,x,m,s,d });
	}
	cout << play();
}