// 1시간 45분

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int arr[50][50];
int commend[2];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int turn[] = { 2,1,3,0 };
int score = 0;
struct ss {
	int num;
	int y;
	int x;
};

void attack() {

	int dir = commend[0] - 1;
	int s = commend[1];

	for (int i = 1; i <= s; i++) {
		int nx = N / 2 + 1 + i * dx[dir];
		int ny = N / 2 + 1 + i * dy[dir];
		arr[ny][nx] = 0;
	}

}

void bomb() {

	deque<int> q;

	int y = N / 2 + 1;
	int x = N / 2 + 1;
	int dir = 0;
	int gap = 1;
	int MAX = 0;
	int num = 4;
	int cnt = 0;
	bool flag = false;
	// 좌 하 우 상 (상하 좌우)
	while (!(y == 1 && x == 1)) {

		MAX++;

		y = y + dy[turn[dir]];
		x = x + dx[turn[dir]];

		if (arr[y][x]) {
			if (num == arr[y][x]) cnt++;
			else {
				if (cnt >= 4) {
					for (int i = 0; i < cnt; i++) {
						q.pop_back();
					}
					score += num * cnt;
				}
				num = arr[y][x];
				cnt = 1;
			}
		}

		if (arr[y][x]) q.push_back(arr[y][x]);

		if (MAX == gap) {
			if (flag == true) {
				gap++;
				flag = false;
			}
			else flag = true;
			MAX = 0;
			dir = (dir + 1) % 4;
		}

		if (y == 1 && x == 1 && cnt >= 4) {
			for (int i = 0; i < cnt; i++) {
				q.pop_back();
			}
			score += num * cnt;
		}
	}
	// 다시터트리기

	flag = true;
	while(flag == true){
		flag = false;
		int qsize = q.size();
		num = 4;
		cnt = 0;
		for (int p = 0; p < qsize; p++) {

			int cmp = q.front();
			q.pop_front();
			if (num == cmp) cnt++;
			else {
				if (cnt >= 4) {
					for (int i = 0; i < cnt; i++) {
						q.pop_back();
					}
					score += num * cnt;
					flag = true;
				}
				num = cmp;
				cnt = 1;
			}
			q.push_back(num);

			if (p == qsize - 1 && cnt >= 4) {
				for (int i = 0; i < cnt; i++) {
					q.pop_back();
				}
				score += num * cnt;
				flag = true;
			}
		}
	}

	// 생성
	int qsize = q.size();
	num = 4;
	cnt = 0;
	for (int p = 0; p < qsize; p++) {
		int cmp = q.front();
		q.pop_front();
		if (num == cmp) cnt++;
		else {
			if (p == 0) {
				num = cmp;
				cnt = 1;
				continue;
			}
			q.push_back(cnt);
			q.push_back(num);
			num = cmp;
			cnt = 1;
		}
		if (p == qsize - 1) {
			q.push_back(cnt);
			q.push_back(num);
		}
	}

	// 넣기
	y = N / 2 + 1;
	x = N / 2 + 1;
	dir = 0;
	gap = 1;
	MAX = 0;
	num = 4;
	cnt = 0;
	while (!(y == 1 && x == 1)) {

		MAX++;
		y = y + dy[turn[dir]];
		x = x + dx[turn[dir]];

		if (!q.empty()) {
			arr[y][x] = q.front();
			q.pop_front();
		}
		else arr[y][x] = 0;

		if (MAX == gap) {
			if (flag == true) {
				gap++;
				flag = false;
			}
			else flag = true;
			MAX = 0;
			dir = (dir + 1) % 4;
		}
	}
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

	for (int p = 0; p < M; p++) {
		cin >> commend[0] >> commend[1];  // 방향 거리
		attack();
		bomb();
	}
	cout << score;
}