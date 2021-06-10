#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, K;
int arr[11][11];
int yang[11][11];

struct is {
	int y;
	int x;
	int age;
};

deque<is> q;

int dy[] = { -1,-1,-1,0,1,1,1,0 };
int dx[] = { -1,0,1,1,1,0,-1,-1 };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			arr[y][x] = 5;
			cin >> yang[y][x];
		}
	}

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		q.push_back({ a,b,c });
	}

	for (int p = 1; p <= K; p++) {

		deque<is> live;
		deque<is> dead;

		// 봄
		int qs = q.size();
		for (int i = 0; i < qs; i++) {

			int y = q.front().y;
			int x = q.front().x;
			int age = q.front().age;
			q.pop_front();

			if (arr[y][x] >= age) {
				arr[y][x] -= age;
				live.push_back({ y,x,age+1 });
			}
			else dead.push_back({ y,x,age });
		}

		// 여름
		int ds = dead.size();
		for (int i = 0; i < ds; i++) {
			
			int y = dead.front().y;
			int x = dead.front().x;
			int age = dead.front().age;
			dead.pop_front();

			arr[y][x] += age / 2;
		}

		// 가을
		int ls = live.size();
		for (int i = 0; i < ls; i++) {

			int y = live.front().y;
			int x = live.front().x;
			int age = live.front().age;
			live.pop_front();

			q.push_back({ y,x,age });
			if (age % 5 == 0) {
				for (int j = 0; j < 8; j++) {
					int ny = y + dy[j];
					int nx = x + dx[j]; 
					if (1 <= ny && ny <= N && 1 <= nx && nx <= N) {
						q.push_front({ ny,nx,1 });
					}
				}
			}
		}
		// 겨울
		
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				arr[y][x] += yang[y][x];
			}
		}
	}

	cout << q.size();

}