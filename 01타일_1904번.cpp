#include<iostream>

using namespace std;

int N;
int dp[1000001];
int main() {
	
	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	cin >> N; 
	// 1 -1개
	// 2 -2개
	// 3 -3개
	// 4 -5개
	// 5 -8개
	//dp[i] = (dp[i - 2] + dp[i - 1]) 점화식이 생성
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746; 
	}

	cout << dp[N];


}