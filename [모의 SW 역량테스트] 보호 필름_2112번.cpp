#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<stdio.h>
using namespace std;

int D, W, K;
bool arr[14][21];
bool temp[14][21];
int MIN = 1e9;

bool check() {
		
	int sum = 0;
	for (int x = 0; x < W; x++) {
		int k = 1;
		int cmp = arr[0][x];
		if (k == K) {
			sum++;
			break;
		}

		for (int y = 1; y < D; y++) {
			if (arr[y][x] == cmp) {
				k++;
				if (k == K) {
					sum++; 
					break;
				}
			}
			else {
				cmp = arr[y][x];
				k = 1;
			}
		}
		if (sum != x + 1) return false;
	}
	if (sum == W) return true;
	else return false;

}

void dfs(int x, int cnt) {

	if (cnt >= MIN && cnt >= K) return;

	if (check() == true) {	
		MIN = min(MIN, cnt);
		return;
	}

	for (int i = x; i < D; i++) {	
		for (int j = 0; j < W; j++) temp[i][j] = arr[i][j];

		for (int j = 0; j < W; j++) arr[i][j] = 0;	
		dfs(i + 1, cnt + 1);

		for (int j = 0; j < W; j++) arr[i][j] = 1;
		dfs(i + 1, cnt + 1);

		for (int j = 0; j < W; j++) arr[i][j] = temp[i][j];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	int T;
	cin >> T; 
	for (int p = 1; p <= T; p++) {
		
		cin >> D >> W >> K;
		MIN = 1e9;

		for (int y = 0; y < D; y++) {
			for (int x = 0; x < W; x++) {
				cin >> arr[y][x];
			}
		}	
		dfs(0, 0);
		cout << "#" << p << " " << MIN << endl;
	}
}