#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, H;
int map[32][11];
int cmp[32][11];
int deep = 0;
int most = 0;
bool finish;

bool check(int cnt) {

	if (cnt == 0)for (int i = 1; i <= N; i++) cmp[0][i] = i;
	if (cnt == H + 1) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (cmp[H + 1][i] == i) cnt++;
		}

		if (cnt == N) return 1;
		else return 0;
	}

	for (int x = 1; x <= N; x++) {
		if (map[cnt + 1][x]) cmp[cnt + 1][x + 1] = cmp[cnt][x];
		else if (map[cnt + 1][x - 1]) cmp[cnt + 1][x - 1] = cmp[cnt][x];
		else cmp[cnt + 1][x] = cmp[cnt][x];
	}

	return check(cnt + 1);

}

void dfs(int idx, int cnt) {

	if (finish == 1) return;

	if (cnt == deep) {
		memset(cmp, false, sizeof(cmp));
		if (check(0)) finish = true;
		return;
	}

	for (int i = idx; i <= (N - 1) * (H + 1); i++) {
		int y = i / (N - 1);
		int x = i % (N - 1) + 1;

		if (y <= H && y >= 1) {
			if (!map[y][x] && !map[y][x + 1] && !map[y][x - 1] && finish != 1) {
				map[y][x] = 2;
				if (x == N - 1) dfs(i + 1, cnt + 1);
				else dfs(i + 2, cnt + 1);
				map[y][x] = false;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 두 가로선이 연속하거나 서로 접하면 안된다. 
	// 사다리 게임은 각각의 세로선마다 게임을 진행
	// N 세로선, H가로선
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}
	for (int i = 1; i <= N; i++) cmp[0][i] = i;

	memset(cmp, false, sizeof(cmp));
	if (check(0)) finish = true;

	for (int k = 0; k <= 3; k++) {
		if (finish == 0) {
			deep = k;
			dfs(1, 0);
		}
		else break;
	}

	if (finish) cout << deep;
	else cout << "-1";

}