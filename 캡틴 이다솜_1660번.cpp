#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[300001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	vector<pair<int, int>> v;
	vector<int> ans;

	v.push_back({ 0,0 });
	v.push_back({ 1,1 });
	dp[1] = 1;
	int MIN = 1;

	cin >> n;

	for (int i = 2; i <= n; i++) {
		v.push_back({ v[i - 1].first + i,0 });
		v[i].second = v[i].first + v[i - 1].second;

		dp[v[i].second] = 1;

		for (int j = 2*v[i].second; j <= n; j += v[i].second) {
			dp[j] = min(dp[j - v[i].second] + 1,dp[j]);
		}

		if (v[i].second > n) {
			MIN = i - 1;
			break;
		}
	}


	for (int i = 2; i <= n; i++) {
		dp[i] = i;
		
		for (int j = 1; i - v[j].second >= 0; j++) {
			dp[i] = min(dp[i], dp[i - v[j].second] + 1);
		}
	}

	cout << dp[n];

}