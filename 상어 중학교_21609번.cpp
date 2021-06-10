#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N, M; // 격자, 색상
int arr[21][21];
int visited[21][21];
int temp[21][21];

struct ss {
	int y;
	int x;
	int size = 0;
	int mo = 0;
};

struct qq {
	int y;
	int x;
};

bool cmp(ss a, ss b) {
	if (a.size == b.size) {
		if (a.mo == b.mo) {
			if (a.y == b.y) return a.x > b.x;
			return a.y > b.y;
		}
		return a.mo > b.mo;
	}
	return a.size > b.size;
}

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

vector<ss> v;

void bfs(int cy, int cx) {
	queue<qq> q;
	queue<qq> store;
	visited[cy][cx] = true;
	q.push({ cy,cx });
	int s = 0;
	int moji = 0;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		if (arr[y][x] == 0) {
			moji++;
			store.push({ y,x });
		}
		s++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && (arr[ny][nx] == arr[cy][cx] || arr[ny][nx] == 0)) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
					
				}
			}
		}
	}

	while (!store.empty()) {
		visited[store.front().y][store.front().x] = false;
		store.pop();
	}

	if (s >= 2) v.push_back({ cy,cx,s,moji});
}

int get_bfs(int cy, int cx) {

	queue<qq> q;
	visited[cy][cx] = true;
	q.push({ cy,cx });
	int sum = 0;
	int number = arr[cy][cx];

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		sum++;
		arr[y][x] = -2;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && (arr[ny][nx] == number || arr[ny][nx] == 0)) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
	return sum * sum;
}

void fall() {
	for (int x = 0; x < N; x++) {
		int idx = N - 1;
		int cur = N - 1;

		while (cur >= 0) {
			if (arr[cur][x] >= 0) {
				if (cur == idx) {
					idx--;
					cur--;
					continue;
				}

				arr[idx][x] = arr[cur][x];
				arr[cur][x] = -2;
				idx--;
			}
			else if (arr[cur][x] == -1) {
				idx = cur - 1;
			}
			cur--;
		}
	}
}

void turn() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			temp[y][x] = arr[x][N - 1 - y];
		}
	}
	memcpy(arr, temp, sizeof(arr));

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 초기 블록 1개씩 검은색,무지개, 일반 블록
	// M가지 색상 검은색 -1 , 무지개 0
	// 그룹에 일반 블록이 적어도 하나, 일반 블록색은 모두 같아야한다. 
	// 검은색 블록 포함 X 무지개는 얼마든지
	// 그룹에 속한 블록의 개수는 2개 이상
	// 한블록에서 그룹에 속한 인접한 칸으로 이동해서 그룹에 속한 다른 모든 칸으로 이동할 수 있어야한다.
	// 블록 그롭의 기준 블록은 무지개 X 블록정에서 행의 번호가 가장 작은 블록. 그게 여러개면 열번호가 가장 작은 블록

	// 크기가 가장 큰 블록 그룹, 그룹이 여러개면 무지개 블록 가장많은거, 같암녀 블록의 행이 가장 큰거, 열이 가장 큰거
	// 위에서 찾은 블록 그룹의 모든 블록제거, 블록의 수의 제곱을 점수로 획득
	// 격자에 중력이 작용
	// 격자가 90도 반시계 방향으로 회전
	// 다시 격자에 중력이 작용

	// 격자에 중력이 작용하면 검은색 블록을 제외한 모든 블록이 행의 번호가 큰카능로 이동
	// 이동은 다른 블록이나 격자의 경계를 만나기 전까지 계속

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int score = 0;

	while (true) { // 게임 시작

		memset(visited, false, sizeof(visited));
		v.clear();

		// 가장 큰블록
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (!visited[j][i] && arr[j][i] > 0) bfs(j, i);
			}
		}

		if (!v.empty()) {
			// 정렬
			sort(v.begin(), v.end(), cmp);
			// 점수 획득
			memset(visited, false, sizeof(visited));
			score += get_bfs(v[0].y, v[0].x);

			// 중력 작용
			fall();
			// 돌려
			turn();
			// 중력
			fall();
		}
		else break;
	}
	cout << score;
}