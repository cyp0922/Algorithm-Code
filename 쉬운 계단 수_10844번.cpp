#include<iostream>
#include<cstring>
#define ll long long
using namespace std;


int dp[101][10];
int MOD = 1e9;
int N;

 int func(int cnt, int x) {

	if (x < 0 || x>9) return 0;
	if (cnt == N) return 1;

	if (dp[cnt][x] != -1) return dp[cnt][x];
	
	return dp[cnt][x] = (func(cnt + 1, x + 1) + func(cnt + 1, x - 1)) % MOD;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> N;	
	memset(dp, -1, sizeof(dp));

	ll ans = 0;  // func(x,i) 의 최대는 9e9-9 이므로 long long 선언
	for (int i = 1; i <= 9; i++) {
		ans += func(1, i); 
	}

	cout << ans % MOD;

}