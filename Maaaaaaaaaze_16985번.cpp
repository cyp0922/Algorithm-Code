// 57Ка

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

bool arr[5][5][5];
bool cmp[5][5][5];
bool visited[5][5][5];
bool rot[5][5];
bool cot[5][5];
bool flat[5];

int dx[] = { -1,0,1,0,0,0 };
int dy[] = { 0,-1,0,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int MIN = 1e9;

struct is {
	int z;
	int y;
	int x;
	int cnt;
};

int bfs() {

	if (!cmp[0][0][0] || !cmp[4][4][4]) return 0;

	memset(visited, false, sizeof(visited));
	queue<is> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int cnt = q.front().cnt;
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= nz && nz < 5 && 0 <= ny && ny < 5 && 0 <= nx && nx < 5 && !visited[nz][ny][nx]) {

				if (nz == 4 && ny == 4 && nx == 4) return cnt + 1;
				if (cmp[nz][ny][nx] == 1) {
					visited[nz][ny][nx] = true;
					q.push({ nz,ny,nx,cnt + 1 });
				}
			}
		}
	}
	return 0;
}

void rotation(int cnt, int k) {

	memcpy(cot, arr[cnt], sizeof(cot));
	memcpy(rot, arr[cnt], sizeof(cot));

	for (int i = 0; i < k; i++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				rot[y][x] = cot[x][4 - y];
			}
		}
		memcpy(cot, rot, sizeof(cot));
	}
}

void func(int cnt) {

	if (cnt == 5) {
		int num = bfs();
		if (num) MIN = min(MIN, num);
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (!flat[i]) {
			flat[i] = true;
			for (int j = 0; j < 4; j++) {
				rotation(i, j);
				memcpy(cmp[cnt], rot, sizeof(cmp[cnt]));
				func(cnt + 1);
			}
			flat[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int z = 0; z < 5; z++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				cin >> arr[z][y][x];
			}
		}
	}

	func(0);
	cout << (MIN == 1e9 ? -1 : MIN);
}