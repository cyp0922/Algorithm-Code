#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int dp[100001];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num;
	cin >> num;
	
	for(int i=0; i<num; i++) cin >> arr[i];

	int ans = arr[0];
	dp[0] = arr[0];
	
	for(int i=1; i<num; i++){
		dp[i] = max(dp[i-1] + arr[i],arr[i]);
		ans = max(ans,dp[i]);
	}
	
	cout <<ans;
}
