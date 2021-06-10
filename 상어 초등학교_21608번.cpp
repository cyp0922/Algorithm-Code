#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int arr[21][21];
int order[401][5];
int temp[401][4];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct ss {
	int y;
	int x;
	int size = 0;
	int em = 0;
};

bool cmp(ss a, ss b) {
	if (a.size == b.size) {
		if (a.em == b.em) {
			if (a.y == b.y) {
				return a.x < b.x;
			}
			return a.y < b.y;
		}
		return a.em > b.em;
	}
	return a.size > b.size;
};

void dfs(int cnt) {

	if (cnt == N * N) {
		int sum = 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				
				int num = 0;				
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						for (int t = 0; t < 4; t++) {
							if (arr[ny][nx] == temp[arr[y][x]][t]) num++;
						}
					}
				}

				if (num == 1) sum = sum + 1;
				else if (num == 2) sum = sum + 10;
				else if (num == 3) sum = sum + 100;
				else if (num == 4) sum = sum + 1000;

			}
		}
		cout << sum;
		return;
	}
	vector<ss> v;
	ss pos;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!arr[j][i]) { // ºñ¾îÀÖ´Â Ä­
				int num = 0;
				int empty = 0;
				for (int k = 0; k < 4; k++) {
					int ny = j + dy[k];
					int nx = i + dx[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (!arr[ny][nx]) empty++;
						for (int t = 1; t <= 4; t++) {
							if (order[cnt][t] == arr[ny][nx]) num++;
						}
					}
				}
				v.push_back({ j,i,num,empty });
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	arr[v[0].y][v[0].x] = order[cnt][0];

	dfs(cnt + 1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> order[i][0];
		for (int j = 1; j <= 4; j++) {
			cin >> order[i][j];
			temp[order[i][0]][j - 1] = order[i][j];
		}
	}

	dfs(0);

}