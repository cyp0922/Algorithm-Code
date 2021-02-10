#include<iostream>
#include<cstring>

using namespace std;

int N, K;
int dp[1001][1001];

int func(int n, int k) {

	if (n == k) return 1;
	if (k == 0) return 1;
	if (k == 1) return n;

	if (dp[n][k] != -1) {
		return dp[n][k];
	}
	return dp[n][k] = (func(n - 1, k - 1) + func(n - 1, k))  % 10007;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// 5 C 2 
	// 5! / (5-2)! 2! 
	//(5,2) => (4,2) + (4,1)
	// (5,2) => (4,1) + (3,1) + (2,1) + (1,1); 
	// (5,3) => (4,3) + (4,2)
	cin >> N >> K;

	memset(dp, -1, sizeof(dp));
	cout << func(N, K);

}