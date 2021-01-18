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

	if (cnt - 1 >= 0 && !visited[cnt - 1] && arr[cnt - 1][R_idx[cnt - 1]] != arr[cnt][L_idx[cnt]]) { // 왼쪽 편
		func(cnt - 1, -dir);
	}
	if ( cnt + 1 < 4 && !visited[cnt + 1] && arr[cnt][R_idx[cnt]] != arr[cnt + 1][L_idx[cnt + 1]]) { // 왼쪽 편
		func(cnt + 1, -dir);
	}


	if (dir == -1) { // 시계 반대방향 인덱스는 증가
		L_idx[cnt] = (L_idx[cnt] + 1) % 8;
		R_idx[cnt] = (R_idx[cnt] + 1) % 8;
	}
	else if (dir == 1) { // 시계 방향 인덱스는 감소
		L_idx[cnt] = L_idx[cnt] - 1;
		if (L_idx[cnt] < 0) L_idx[cnt] = 7;
		R_idx[cnt] = R_idx[cnt] - 1;
		if (R_idx[cnt] < 0) R_idx[cnt] = 7;
	}

}

int main() {


	// 극 이 다르다면 반대방향 회전
	// 12시 방향 부터 시계 방향으로 N극은 0 / S극은 1

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 8; i++) {
			scanf_s("%1d", &arr[j][i]);
		}
	}

	for (int i = 0; i < 4; i++) { // 톱니 초기 인덱스 지정
		R_idx[i] = 2;
		L_idx[i] = 6;
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> n >> d; // dir 의 1 인경우 시계방향/ -1인 경우 반시계방향 
						 // 인덱스는 거꾸로 적용된다.
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