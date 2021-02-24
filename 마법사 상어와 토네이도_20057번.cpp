#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int N;
int map[500][500];

int range = 1;
int cnt = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int dir = 0;

int wx[] = { -1,-1,0,0,0,0,1,1,2 };
int wy[] = { 1,-1,1,-1,2,-2,1,-1,0 };
int wp[] = { 1,1,7,7,2,2,10,10,5 };

int ans = 0;



void wind(int y, int x, int sum) {
	
	int cnt = 0;

	int ny;
	int nx;
	for (int i = 0; i < 9; i++) {
		if (dir == 0) {
			ny = y + wy[i];
			nx = x - wx[i];
		}
		else if (dir == 1) {
			ny = y + wx[i];
			nx = x + wy[i];
		}
		else if (dir == 2) {
			ny = y + wy[i];
			nx = x + wx[i];
		}
		else if (dir == 3) {
			ny = y - wx[i];
			nx = x - wy[i];
		}

		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
			map[ny][nx] += sum * wp[i] / 100;
			cnt += sum * wp[i] / 100;
		}
		else {
			ans += sum * wp[i] / 100;
			cnt += sum * wp[i] / 100;
		}
	}
	map[y][x] = 0;
	if (dir == 0 || dir == 2) {
		int mx = x + dx[dir];
		if (mx >= 0 && mx < N) map[y][mx] += sum - cnt;
		else ans += sum - cnt;
	}
	else if (dir == 1 || dir == 3) {
		int my = y + dy[dir];
		if (my >= 0 && my < N) map[my][x] += sum - cnt;
		else ans += sum - cnt;
	}

}

void move(int y_, int x_) {

	if (y_ == 0 && x_ == 0) return;
	if (y_ == 0 && x_ == N - 1) range--; 

	int ny = y_ + dy[dir]; 
	int nx = x_ + dx[dir];

	wind(ny, nx, map[ny][nx]);

	cnt++;
	if(cnt == range || cnt == 2*range) dir = (dir + 1) % 4;

	if (cnt == 2*range) {
		range++;
		cnt = 0;
	}

	move(ny, nx);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	// Y의 모든 모래가 비율과 a가 적혀있는 칸으로 이동
	// 비율이 적혀있는 칸으로 이동하는 모래의 양은 y에 있는 모래의 해당 비율 만큼
	// 계산은 소수점 아래로 버린다
	// a로 이동하는 모래의 양은 비율이 적혀있는 칸으로 이동하지 않는 남은 모래의 양과같다
	// 모래가 이미 있는 칸으로 이동하면, 모래의 양은 더해진다.
	// 해당 방향으로 회전

	cin >> N; 
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) cin >> map[y][x];
	}

	move(N / 2, N / 2);

	cout << ans;
}