#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[1002][1002];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input, cmp;

	cin >> input;
	cin >> cmp;



	for (int i = 1; i <= input.size() + 1; i++) {

		for (int j = 1; j <= cmp.size() + 1; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			dp[i][j] = max(dp[i][j - 1], dp[i][j]);
			if (input[i - 1] == cmp[j - 1]) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
			}
		}
	}


	cout << dp[input.size() + 1][cmp.size() + 1];


}