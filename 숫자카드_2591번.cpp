#include<iostream>
#include<string>

using namespace std;
int dp[41];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	if (input[0]-'0' == 0) {
		cout << "0"; 
		exit(0);
	}

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= input.size(); i++) {

		if (input[i - 1] - '0' != 0) {
			if (10 * (input[i - 2] - '0') + input[i - 1] - '0' <= 34 && input[i - 2] - '0' != 0) {
				dp[i] = dp[i - 2] + dp[i - 1];
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		else if(input[i - 2] - '0' == 0) dp[i] = 0;
		else if(10 * (input[i - 2] - '0') + input[i - 1] - '0' <= 34) dp[i] = dp[i - 2];
		
	}

	cout << dp[input.size()];

}