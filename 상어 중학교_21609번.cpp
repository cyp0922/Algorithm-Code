#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N, M; // ����, ����
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

	// �ʱ� ��� 1���� ������,������, �Ϲ� ���
	// M���� ���� ������ -1 , ������ 0
	// �׷쿡 �Ϲ� ����� ��� �ϳ�, �Ϲ� ��ϻ��� ��� ���ƾ��Ѵ�. 
	// ������ ��� ���� X �������� �󸶵���
	// �׷쿡 ���� ����� ������ 2�� �̻�
	// �Ѻ�Ͽ��� �׷쿡 ���� ������ ĭ���� �̵��ؼ� �׷쿡 ���� �ٸ� ��� ĭ���� �̵��� �� �־���Ѵ�.
	// ��� �׷��� ���� ����� ������ X ��������� ���� ��ȣ�� ���� ���� ���. �װ� �������� ����ȣ�� ���� ���� ���

	// ũ�Ⱑ ���� ū ��� �׷�, �׷��� �������� ������ ��� ���帹����, ���ϳ� ����� ���� ���� ū��, ���� ���� ū��
	// ������ ã�� ��� �׷��� ��� �������, ����� ���� ������ ������ ȹ��
	// ���ڿ� �߷��� �ۿ�
	// ���ڰ� 90�� �ݽð� �������� ȸ��
	// �ٽ� ���ڿ� �߷��� �ۿ�

	// ���ڿ� �߷��� �ۿ��ϸ� ������ ����� ������ ��� ����� ���� ��ȣ�� ūī�ɷ� �̵�
	// �̵��� �ٸ� ����̳� ������ ��踦 ������ ������ ���

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int score = 0;

	while (true) { // ���� ����

		memset(visited, false, sizeof(visited));
		v.clear();

		// ���� ū���
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (!visited[j][i] && arr[j][i] > 0) bfs(j, i);
			}
		}

		if (!v.empty()) {
			// ����
			sort(v.begin(), v.end(), cmp);
			// ���� ȹ��
			memset(visited, false, sizeof(visited));
			score += get_bfs(v[0].y, v[0].x);

			// �߷� �ۿ�
			fall();
			// ����
			turn();
			// �߷�
			fall();
		}
		else break;
	}
	cout << score;
}