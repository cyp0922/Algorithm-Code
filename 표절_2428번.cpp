#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int arr[100001];

int func(int idx, int end) {
	
	int l = idx;
	int r = end;
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (arr[mid] * 0.9 <= arr[idx]) l = mid + 1;
		else r = mid;
	}
	return r-1;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	//작은파일의 크기가 큰 파일 크기의 90퍼 보다 작을때는 이러한 쌍은 검사하지 않고 넘어간다
	// size (f) <= size(f) , size(f) >= 0.9 size(f)
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr , arr + n);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans += func(i, n) - i;		
	}

	cout << ans;



}