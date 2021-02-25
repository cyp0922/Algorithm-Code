#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int a[10001];
int b[10001];
int dp[10001][10][2];
int MAX = 2e9; 
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%1d", &b[i]);
	}

	memset(dp, 0x3f, sizeof(dp));

	for (int i = 0; i <= 9; i++) dp[0][i][0] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {

			int lcnt = (b[i] - (j + a[i]) + 20) % 10;
			int rcnt = 10 - lcnt;

			if (dp[i][j][0] > dp[i - 1][j][0] + rcnt) {
				dp[i][j][0] = dp[i - 1][j][0] + rcnt;
				dp[i][j][1] = -rcnt;
			}

			if (dp[i][(j + lcnt) % 10][0] > dp[i - 1][j][0] + lcnt) {
				dp[i][(j + lcnt) % 10][0] = dp[i - 1][j][0] + lcnt;
				dp[i][(j + lcnt) % 10][1] = lcnt;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		MAX = min(dp[N][i][0], MAX);
	}

	vector<pair<int,int>> v;

	for (int i = 0; i <= 9; i++) {
		if (MAX == dp[N][i][0]) {

			int temp = i;
			int memo = temp;
			for (int j = N; j > 0; j--) {

				v.push_back({ j,dp[j][temp][1] });
				memo = temp;
				if (dp[j][temp][1] > 0) {
					temp = ( memo - dp[j][temp][1] + 10) % 10;
				}
			}

			break;
		}
	}

	cout << MAX << "\n"; 

	for (int i = v.size() - 1; i >= 0; i--) cout << v[i].first << " " << v[i].second << "\n";

}