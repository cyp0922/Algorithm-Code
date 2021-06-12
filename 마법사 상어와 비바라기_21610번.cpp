// 1시간 30분

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
int arr[51][51];
bool visited[51][51];
int commend[100][2]; // 방향 이동칸

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

struct ss {
	int y;
	int x;
};

vector<ss> cloud;

void move_cloud_rain(int cnt) {

	int dir = commend[cnt][0] - 1;
	int speed = commend[cnt][1];

	for (int i = 0; i < cloud.size(); i++) {

		int y = cloud[i].y;
		int x = cloud[i].x;
		int ny = 0;
		int nx = 0;

		ny = y + (speed * dy[dir] % N);
		nx = x + (speed * dx[dir] % N);

		if (ny <= 0) ny = N + ny;
		if (nx <= 0) nx = N + nx;
		if (ny > N) ny = ny - N;
		if (nx > N) nx = nx - N;

		cloud[i].y = ny;
		cloud[i].x = nx;
		arr[ny][nx] ++;
		visited[ny][nx] = true;

	}
}

void water_copy() {

	for (int k = 0; k < cloud.size(); k++) {

		int y = cloud[k].y;
		int x = cloud[k].x;

		for (int i = 1; i < 8; i += 2) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && arr[ny][nx]) {
				arr[y][x] ++;
			}
		}
	}
	cloud.clear();
}

void make_cloud() {

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (arr[y][x] >= 2 && !visited[y][x]) {
				cloud.push_back({ y,x });
				arr[y][x] -= 2;
			}
		}
	}
	memset(visited, false, sizeof(visited));
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> commend[i][0] >> commend[i][1];
	}

	// 초기값
	cloud.push_back({ N, 1 });
	cloud.push_back({ N, 2 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 1, 2 });

	for (int p = 0; p < M; p++) {
		move_cloud_rain(p);
		water_copy();
		make_cloud();
	}

	int sum = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			sum += arr[y][x];
		}
	}
	cout << sum;
}