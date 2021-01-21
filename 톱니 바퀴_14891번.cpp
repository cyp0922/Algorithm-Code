#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[4][8];
int L_idx[4];
int R_idx[4];
int K, n, d;

bool visited[4];

void func(int cnt, int dir) {

	visited[cnt] = true;

	if (cnt - 1 >= 0 && !visited[cnt - 1] && arr[cnt - 1][R_idx[cnt - 1]] != arr[cnt][L_idx[cnt]]) { // ���� ��
		func(cnt - 1, -dir);
	}
	if ( cnt + 1 < 4 && !visited[cnt + 1] && arr[cnt][R_idx[cnt]] != arr[cnt + 1][L_idx[cnt + 1]]) { // ���� ��
		func(cnt + 1, -dir);
	}


	if (dir == -1) { // �ð� �ݴ���� �ε����� ����
		L_idx[cnt] = (L_idx[cnt] + 1) % 8;
		R_idx[cnt] = (R_idx[cnt] + 1) % 8;
	}
	else if (dir == 1) { // �ð� ���� �ε����� ����
		L_idx[cnt] = L_idx[cnt] - 1;
		if (L_idx[cnt] < 0) L_idx[cnt] = 7;
		R_idx[cnt] = R_idx[cnt] - 1;
		if (R_idx[cnt] < 0) R_idx[cnt] = 7;
	}

}

int main() {


	// �� �� �ٸ��ٸ� �ݴ���� ȸ��
	// 12�� ���� ���� �ð� �������� N���� 0 / S���� 1

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 8; i++) {
			scanf_s("%1d", &arr[j][i]);
		}
	}

	for (int i = 0; i < 4; i++) { // ��� �ʱ� �ε��� ����
		R_idx[i] = 2;
		L_idx[i] = 6;
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> n >> d; // dir �� 1 �ΰ�� �ð����/ -1�� ��� �ݽð���� 
						 // �ε����� �Ųٷ� ����ȴ�.
		func(n-1, d);
		memset(visited, false, sizeof(visited));

	}

	int sum = 0;
	for (int i = 0; i < 4; i++) {

		int temp = R_idx[i] - 2;
		if (temp < 0) temp = temp + 8;

		if (arr[i][temp] == 1) sum += pow(2, i);
	}

	cout << sum;

}