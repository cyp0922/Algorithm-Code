#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int arr[5000001];

int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> arr[i]; 

	int l = -1e9;
	int r = 1e9;
	int cnt = 0, mid;

	while (l <= r) {

		cnt = 0;
		mid = (l + r) / 2;

		for (int i = 0; i < N; i++) {
			if (arr[i] <= mid) cnt++;
		}

		if (cnt >= K) r = mid - 1;
		else l = mid + 1;

	}

	cout << l;

	

}