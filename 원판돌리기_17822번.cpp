#include<iostream>
#include<cstring>
using namespace std;

int N, M, T;
int command[52][3];
int circle[52][51];
int cmp[52][51];
int idx[52];

int del() {

	bool flag = false;

	memcpy(cmp, circle, sizeof(cmp));

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] != 0) {
				// 같은 원판
				bool cur = false;
				int k = j + 1;
				if (circle[i][j] == circle[i][k % M]) {
					cmp[i][k % M] = 0;
					cur = true;
				}

				if (cur == true) {
					cmp[i][j] = 0;
					flag = true;
				}
			}

			// 다른 원판
			if (circle[i][(idx[i] + j) % M] != 0) {
				if ( circle[i][(idx[i] + j) % M] == circle[i + 1][(idx[i + 1] + j) % M]) {
					cmp[i][(idx[i] + j) % M] = cmp[i + 1][(idx[i + 1] + j) % M] = 0;
					flag = true;
				}
			}
		}
	}

	memcpy(circle, cmp, sizeof(circle));
	return flag;
}

void rotation(int i, int cnt) {

	int cur = idx[i];

	if (cnt > 0) {
		cur = (cur + cnt) % M;
	}

	else if (cnt < 0) {
		if (cur + cnt < 0) cur = M + (cur + cnt);
		else cur = cur + cnt;
	}

	idx[i] = cur;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// T번 회전
	// 1.Xi의 배수인 원판을 di방향으로 kj칸 회전시킨다. 
	// 0 시계방향, 1반시계 방향

	//2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다. 
	// 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다. 
	// 없는 경우에는 원판에 적힌 수의 평균을 구하고, 
	// 평균보다 큰수에서 1을 빼고, 작은 수에는 1을 더한다. 

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 1; i <= T; i++) cin >> command[i][0] >> command[i][1] >> command[i][2];

	// 돌리기 시작
	for (int p = 1; p <= T; p++) {

		// x d k  배수 방향 회전 칸
		int x = command[p][0];
		int dir;
		if (command[p][1] == 0) dir = -1; // 시계 방향
		else dir = 1;
		int k = command[p][2];

		
		for (int i = x; i <= N; i = i + x) { // 배수
			rotation(i, k * dir);
		}

		if (!del()) { // 지울게 없다면
			float sum = 0; float num = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (circle[i][j] != 0) {
						num++;
						sum += circle[i][j];
					}
				}
			}

			float average = sum / num;
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (circle[i][j] != 0) {
						if ((float)circle[i][j] < average) circle[i][j]++;
						else if ((float)circle[i][j] > average) circle[i][j]--;
					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += circle[i][j];
		}
	}
	cout << sum;
}