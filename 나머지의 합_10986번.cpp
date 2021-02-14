#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int N, M;
int arr[1000001];
int store[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	ll ans = 0;
	ll sum = 0;

	for (int i = 1; i <= N; i++) {
		sum += arr[i];
		if (sum % M == 0) {
			ans++;
			ans += store[sum % M];
		}
		else if(store[sum % M]){
			ans += store[sum % M];
		}
		store[sum % M]++;
	}

	cout << ans;
}