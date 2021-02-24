#include<iostream>
#include<cstring>

using namespace std;

int dp[33335];
int N;
int MOD = 1e9 + 9;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	dp[1] = 2;

	long long temp;
	for (int i = 2; i <= N; i++) {
		temp = (long long)dp[i - 1] * 3 % MOD;
		dp[i] = temp;
	}

	cout << dp[N - 1];
}