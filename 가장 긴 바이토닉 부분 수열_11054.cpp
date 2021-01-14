#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001][2];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; 
	}

	int MAX = 0;
	for (int i = 0; i < N; i++) {

		dp[i][0] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}

		for (int j = N-1; j > N - 1 - i; j--) {
			if (arr[j] < arr[N - 1 - i]) {
				dp[N - 1 - i][1] = max(dp[N - 1 - i][1], dp[j][1]+1);
			}
		}
	}

	for (int i = 0; i < N; i++) MAX = max(MAX, dp[i][0] + dp[i][1] );

	cout << MAX;
	
}