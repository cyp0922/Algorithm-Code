#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int r, c, k, n = 3;
int R = 3, C = 3;
int A[101][101];

bool cmp(pair<int, int> a, pair<int, int> b) {
	
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> k;  //  r - x  c - y

	for (int y = 1; y <=n; y++) {
		for (int x = 1; x <=n; x++) {
			cin >> A[y][x];
		}
	}

	int MAX = 0;

	for (int t = 0; t <= 100; t++) {

		if (A[r][c] == k) {
			cout << t;
			exit(0);
		}

		MAX = 0;

		if (C >= R) { // C 행 (Y) R 열 (X)
			for (int y = 1; y <= C; y++) {

				vector<pair<int, int>> v;
				for (int x = 1; x <= R; x++) {

					if (v.size() == 0 && A[y][x]) {
						v.push_back({ A[y][x], 1 });
						A[y][x] = 0;
						continue; // x =1이 중복되지않기 위해
					}
					else if (v.size() == 0) continue;

					bool flag = false;

					for (int i = 0; i < v.size(); i++) {
						if (v[i].first == A[y][x]) {
							v[i].second++;
							flag = true;
							A[y][x] = 0;
							break;
						}
					}
					if (A[y][x] && flag == false) {
						v.push_back({ A[y][x] ,1 });
						A[y][x] = 0;
					}

				}

				sort(v.begin(), v.end(), cmp);

				int temp = 2 * v.size();
				MAX = max(MAX, temp);

				for (int x = 0; x < v.size(); x++) {
					if (x == 50) break;
					A[y][2 * (x + 1) - 1] = v[x].first;
					A[y][2 * (x + 1)] = v[x].second;
				}
			}

			if (MAX > 100) R = 100;
			else R = MAX;
		}
		// 열 정렬
		else {
			for (int x = 1; x <= R; x++) {

				vector<pair<int, int>> v;
				for (int y = 1; y <= C; y++) {

					if (v.size() == 0 && A[y][x]) {
						v.push_back({ A[y][x], 1 });
						A[y][x] = 0;
						continue; // y =1이 중복되지않기 위해
					}
					else if (v.size() == 0) continue;

					bool flag = false;

					for (int i = 0; i < v.size(); i++) {
						if (v[i].first == A[y][x]) {
							v[i].second++;
							flag = true;
							A[y][x] = 0;
							break;
						}
					}
					if (A[y][x] && flag == false) {
						v.push_back({ A[y][x] ,1 });
						A[y][x] = 0;
					}

				}

				sort(v.begin(), v.end(), cmp);

				int temp = 2 * v.size();
				MAX = max(MAX, temp);

				for (int y = 0; y < v.size(); y++) {
					if (y == 50) break;
					A[2 * (y + 1) - 1][x] = v[y].first;
					A[2 * (y + 1)][x] = v[y].second;
				}
			}

			if (MAX > 100) C = 100;
			else C = MAX;

			//
		}

	}

	cout << "-1";

}