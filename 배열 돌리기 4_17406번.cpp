#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N, M, K;
int arr[51][51];
int cmp[51][51];
int com[7][3];
int com_v[7];
int MIN = 1e9;
vector<int> order;

void turn(int cy, int cx, int gap) {

	int temp1,temp2;
	
	for (int num = 0; num < gap; num++) {

		int g = gap - num;

		temp1 = cmp[cy - g][cx + g];
		// 상단
		for (int x = cx + g; x > cx - g; x--) {
			cmp[cy - g][x] = cmp[cy - g][x - 1];
		}
		// 우측
		temp2 = cmp[cy + g][cx + g];
		for (int y = cy + g; y > cy - g; y--) {
			cmp[y][cx + g] = cmp[y - 1][cx + g];
		}
		cmp[cy - g + 1][cx + g] = temp1;
		// 하단
		temp1 = cmp[cy + g][cx - g];
		for (int x = cx - g; x < cx + g; x++) {
			cmp[cy + g][x] = cmp[cy + g][x + 1];
		}
		cmp[cy + g][cx + g - 1] = temp2;
		// 좌측
		temp2 = cmp[cy - g][cx - g];
		for (int y = cy - g; y < cy + g; y++) {
			cmp[y][cx - g] = cmp[y + 1][cx - g];
		}
		cmp[cy + g - 1][cx - g] = temp1;
		cmp[cy - g][cx - g + 1] = temp2;
	}
}

void func(int cnt) {
	
	if (cnt == K) {

		memcpy(cmp, arr, sizeof(cmp));
		// 돌리기
		for (int i = 0; i < order.size(); i++) {
			turn(com[order[i]][0], com[order[i]][1], com[order[i]][2]);
		}
		// 행렬의 합
		int sum;
		int row_Min = 1e9;
		for (int y = 1; y <= N; y++) {
			sum = 0;
			for (int x = 1; x <= M; x++) {
				sum += cmp[y][x];
			}
			row_Min = min(row_Min, sum); 
		}

		MIN = min(MIN, row_Min);
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!com_v[i]) {
			order.push_back(i);
			com_v[i] = true;
			func(cnt + 1);
			com_v[i] = false;
			order.pop_back();
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M >> K;
	
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) cin >> com[i][j];
	}

	func(0);
	
	cout << MIN;
}