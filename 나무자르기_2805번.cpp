#include<iostream>

using namespace std;

int arr[1000000];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, H;
	cin >> N >> M; // 나무의 수, 나무의 길이
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int l = 0;
	int r = 2e9;
	long long cnt = 0;
	int mid;
	while (l <= r) {

		cnt = 0;

		mid = (l + r) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] - mid >= 0) {
				cnt += ((long long)arr[i] - (long long)mid);
			}
		}
		if (cnt >= M) l = mid + 1;
		else r = mid - 1;

	}

	if (l > 0) cout << l - 1;
	else cout << l;

}