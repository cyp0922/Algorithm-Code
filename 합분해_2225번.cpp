#include<iostream>
using namespace std;

int N, K;
int dp[201][201];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		dp[i][1] = i;
		for (int j = 2; j <= N; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
		}
	}

	cout << dp[K][N];
}