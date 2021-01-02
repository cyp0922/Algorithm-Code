#include<iostream>
using namespace std;

int N;
int arr[101];
bool is[1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int MAX=0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
		cnt++;

		if (arr[i] == 1) cnt--;
		for (int j = 2; j <= arr[i] / 2; j++) {
			if (arr[i] % j == 0) {
				cnt--;
				break;
			}
		}

	}

	cout << cnt;
}