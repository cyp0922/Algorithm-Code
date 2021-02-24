#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int arr[101];
int dp[10001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//n가지 종류 동전, 합이 k원 동전의 개수가 최소

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= k; i++) dp[i] = 100001;
	
	for (int j = 1; j <= n; j++) {
		for (int i = arr[j]; i <= k; i++) {
			dp[i] = min(dp[i],dp[i-arr[j]] +1);
		}
	}

	if (dp[k] != 100001) cout << dp[k];
	else cout << "-1";
	
}