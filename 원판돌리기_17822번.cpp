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
				// ���� ����
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

			// �ٸ� ����
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

	// T�� ȸ��
	// 1.Xi�� ����� ������ di�������� kjĭ ȸ����Ų��. 
	// 0 �ð����, 1�ݽð� ����

	//2. ���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�. 
	// �׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����. 
	// ���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, 
	// ��պ��� ū������ 1�� ����, ���� ������ 1�� ���Ѵ�. 

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 1; i <= T; i++) cin >> command[i][0] >> command[i][1] >> command[i][2];

	// ������ ����
	for (int p = 1; p <= T; p++) {

		// x d k  ��� ���� ȸ�� ĭ
		int x = command[p][0];
		int dir;
		if (command[p][1] == 0) dir = -1; // �ð� ����
		else dir = 1;
		int k = command[p][2];

		
		for (int i = x; i <= N; i = i + x) { // ���
			rotation(i, k * dir);
		}

		if (!del()) { // ����� ���ٸ�
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