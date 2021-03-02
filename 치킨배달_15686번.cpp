#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[51][51];
int visited[51][51]; 
int cmp[51][51];

vector<pair<int, int>> chi;
int chi_visited[14];
vector<int> store;
vector < pair<int, int> >home;

int MIN = 1e9;

void func(int x, int cnt) {
	
	if (cnt == M) {
	
		int sum = 0;
		int cmp = 1e9;
		for (int i = 0; i < home.size(); i++) {

			cmp = 1e9;

			int hy = home[i].first;
			int hx = home[i].second;

			for (int i = 0; i < store.size(); i++) {
				int sy = chi[store[i]].first;
				int sx = chi[store[i]].second;

				int temp = abs(sy - hy) + abs(sx - hx); 

				cmp = min(cmp, temp);
			}

			sum += cmp;
		}

		MIN = min(MIN, sum);

		return;
	}

	for (int i = x+1; i < chi.size(); i++) {

		if (!chi_visited[i]) {
			chi_visited[i] = true;
			store.push_back(i);
			func(i, cnt + 1);
			store.pop_back();
			chi_visited[i] = false;
		}

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 0Àº ºóÄ­ , 1Àº Áý , 2´Â Ä¡Å²Áý

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				chi.push_back({ y,x });
				map[y][x] = 0;
			}
			if (map[y][x] == 1) home.push_back({ y,x });
		}
	}
		

	func(-1, 0);
	cout << MIN;

}