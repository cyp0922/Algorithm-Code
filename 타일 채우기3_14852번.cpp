#include<iostream>
#define ll long long

using namespace std;

int dp[1000001];
const int MAX = 1e9 + 7;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;

	// 2*dp(n-1) + 3*dp(n-2) + 2*( dp(n-3) + dp(n-4) + dp(n-5) + ... + dp(0))

	dp[1] = 2;
	dp[2] = 7;

	ll temp = 1;

	for (int i = 3; i <= N; i++) {
		temp = ((ll)dp[i - 3] + temp) % MAX;
		dp[i] = (2 * (ll)dp[i - 1] + 3 * (ll)dp[i - 2] + 2 * temp) % MAX;
	}

	cout << dp[N];

}