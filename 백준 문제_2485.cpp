#include<iostream>
using namespace std;

int arr[100001];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;
	int MIN = 0;

	for (int i = 1; i <= N; i++) {

		cin >> arr[i];

		int temp = arr[i] - arr[i - 1];
		if (i == 2) MIN = arr[2] - arr[1];
		if (i >= 3 && temp % MIN != 0) {

			int small = temp < MIN ? temp : MIN;
			int big = temp > MIN ? temp : MIN;
			MIN = big % small; // 최소 공배수

		}
	
	}

	int sum = 0;

	for (int i = 2; i <= N; i++) {
		sum += (arr[i] - arr[i - 1]) / MIN - 1;
	}

	cout << sum;
}