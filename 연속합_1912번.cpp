#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int dp[100001];
int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> dp[i];

	int idx = 0;
	int sum = 0;
	int MAX = dp[1];

	for (int i = 2; i <= N; i++) {
		
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);

		MAX = max(MAX, dp[i]);
	}

	cout << MAX;
}