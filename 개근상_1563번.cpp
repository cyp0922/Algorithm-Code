#include<iostream>

using namespace std;

int dp[1001][2][3];
const int MOD = 1000000;
int N;

int func(int c, int l, int a) {

	if (l == 2) return 0;
	if (a == 3) return 0;

	if (c == N) return 1;
	
	if (dp[c][l][a] != -1) {
		return dp[c][l][a];
	}
	
	dp[c][l][a] = (func(c + 1, l, 0) + func(c + 1, l + 1, 0) + func(c + 1, l, a + 1)) % MOD;

	return dp[c][l][a];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 출결/ 출석,지각,결석
	// 지각을 2번이상, 결석 세번연속 개근상x
	// 한학기 4일 O출석 L지각 A 결석
	// 한학기 N일 

	cin >> N;

	memset(dp, -1, sizeof(dp));
	
	cout << func(0, 0, 0);

}