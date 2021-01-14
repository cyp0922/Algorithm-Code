#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];
int MAX = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			MAX = max(MAX, dp[i][j]);
		}
	}

	cout << MAX;


}