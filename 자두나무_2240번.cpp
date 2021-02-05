#include<iostream>
#include<algorithm>

using namespace std;

bool arr[1002];
int dp[2][1002][32];
int MAX = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, W;

	cin >> T >> W;

	int input;
	for (int i = 1; i <= T; i++) {
		cin >> input;
		if (input - 1 == 1) arr[i] = true;
		else arr[i] = false;
	}

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W+1; j++) {
			
			if (arr[i] == 0) {
				dp[0][i][j] = max(dp[0][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1);
				dp[1][i][j] = max(dp[0][i - 1][j - 1], dp[1][i - 1][j]);
			}
			else {
				if (i == 1 && j == 1) continue;
				dp[1][i][j] = max(dp[0][i - 1][j - 1] + 1, dp[1][i - 1][j] + 1);
				dp[0][i][j] = max(dp[0][i - 1][j], dp[1][i - 1][j - 1]);
			}	
		}
	}

	for (int i = 1; i <= W+1; i++) {
		MAX = max(MAX, max(dp[1][T][i], dp[0][T][i]));
	}

	cout << MAX;

}