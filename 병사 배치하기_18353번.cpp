#include<iostream>
#include<iostream>

using namespace std;

int N;
int dp[2001];
int arr[2001];
int MAX = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		MAX = max(MAX, dp[i]);
	}

	cout << N - MAX;

}