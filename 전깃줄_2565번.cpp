#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int dp[102];
vector<pair<int,int>> arr; 

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> N;

	int a, b;

	for (int i = 0; i <N; i++) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end(), cmp);

	int MAX = 0;

	for (int i = 0; i < N; i++) {

		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		MAX = max(MAX, dp[i]);
	}
	

	cout << N - MAX;

}