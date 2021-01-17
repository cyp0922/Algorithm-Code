#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[100001];
bool arr[100001];
int B, K, N;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0); 

	// 26마리 52개 점

	cin >> N >> K >> B; // 횡단 번호, 연속K개 ,고장 난 번호

	int input;
	for (int i = 1; i <=B; i++) {
		cin >> input;
		arr[input] = true;
	}

	int MAX = 0;
	int cnt = 0;

	for (int i = 1; i <=N; i++) {

		if (arr[i] == 0) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];

		if (i>=K) MAX = max(MAX, dp[i] - dp[i-K]);

	}

	cout << K- MAX;

}