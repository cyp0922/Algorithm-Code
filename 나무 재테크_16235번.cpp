#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;

int N, M, K;
int A[11][11];
int map[11][11];
deque<pair<int, pair<int, int>>> dq;

int dx[] = { -1,0,1,1,1,0,-1,-1 }; // 왼쪽 상단부터
int dy[] = { -1,-1,-1,0,1,1,1,0 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K; // 

	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			cin >> A[j][i];
			map[j][i] = 5;
		}
	}

	int x, y, z; // 위치 나무
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		dq.push_back({ z,{ x, y } });
	}

	for (int p = 0; p < K; p++) {

		queue<pair<int, pair<int, int>>> live;
		queue<pair<int, pair<int, int>>> dead;

		while (!dq.empty()) { // 봄
			int b = dq.front().second.first;
			int a = dq.front().second.second;
			int age = dq.front().first;
			dq.pop_front();

			if (map[b][a] - age >= 0) {
				map[b][a] = map[b][a] - age;
				age++;
				live.push({ age,{b,a} });
			}
			else { // 죽는 나무
				dead.push({ age,{b,a} });
			}

		}

		while (!dead.empty()) { // 여름

			int b = dead.front().second.first;
			int a = dead.front().second.second;
			int age = dead.front().first;
			dead.pop();

			map[b][a] += age / 2;

		}

		while (!live.empty()) { // 가을

			int b = live.front().second.first;
			int a = live.front().second.second;
			int age = live.front().first;
			live.pop();
			dq.push_back({ age,{b,a} });

			if (age % 5 == 0) {

				for (int i = 0; i < 8; i++) {
					int nx = a + dx[i];
					int ny = b + dy[i];
					if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
						dq.push_front({ 1,{ny,nx} });
					}
				}
			}

		}

		//겨울
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				map[j][i] += A[j][i];
			}
		}
	}

	cout << dq.size();

}