#include<iostream>
#include<algorithm>

using namespace std; 

int N,K;
int arr[101];
int dp[10001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >>K;

	//N 동전 갯수 , K 원

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N+1); 

	for (int i = 1; i <= N; i++) {
		
		dp[0] = 1;

		for (int j = 1; j <= K; j++) { // 동전
			if (arr[i] <= j) {
				dp[j] = dp[j] + dp[j - arr[i]];
			}
		}

	}

	cout << dp[K];


}