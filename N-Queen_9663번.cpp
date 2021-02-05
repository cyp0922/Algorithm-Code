#include<iostream>
#include<cstring>

using namespace std;

int N;
int arr[16];
int ans = 0;

bool check(int row) {

	for (int i = 0; i < row; i++) {
		if (arr[row] == arr[i] || abs(arr[row] - arr[i]) == row - i) return 0;
	}

	return 1;
}

void func(int x) {

	if (x == N) ans++;

	for (int i = 0; i < N; i++) {
		arr[x] = i;
		if (check(x)) func(x + 1);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	func(0);
	cout << ans;

}