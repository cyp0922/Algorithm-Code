#include<iostream>
#include<cstring>
using namespace std;

int N;
int dp[101][11][1024];
const int MOD = 1e9;

int func(int x, int cnt, int visited) {

	if (x < 0 || x > 9) return 0;
	
	if (cnt == N) {
		if ((visited & 1023) == 1023) {
			return 1;
		}
		return 0;
	}

	if (dp[cnt][x][visited] != -1) {
		return dp[cnt][x][visited];
	}

	if ((visited & (1 << (x-1) )) > 0 && (visited & (1 << (x + 1))) > 0) dp[cnt][x][visited] = (func(x - 1, cnt + 1, visited) + func(x + 1, cnt + 1, visited)) % MOD;
	else if (visited & (1 << (x -1)))  dp[cnt][x][visited] = (func(x - 1, cnt + 1, visited) + func(x + 1, cnt + 1, visited + (1 << (x + 1)))) % MOD;
	else if (visited & (1 << (x+1)) )  dp[cnt][x][visited] = (func(x - 1, cnt + 1, visited + (1 << (x - 1))) + func(x + 1, cnt + 1, visited )) % MOD;
	else dp[cnt][x][visited] = (func(x - 1, cnt + 1, visited + (1 << (x - 1))) + func(x + 1, cnt + 1, visited + (1 << (x + 1) ) ) ) % MOD;

	return dp[cnt][x][visited];
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	memset(dp, -1, sizeof(dp));

	long long ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += func(i, 1, 1 << i);
	}
	
	cout << ans % MOD; 
}