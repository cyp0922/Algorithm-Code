#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1000001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N; 
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);
	
	int i = 0;
	int sum = 0;

	for (int a = 0; a < N % 3; a++) {
		sum += arr[a];
		i++;
	}

	while(i < N) {
		
		if (i + 2 < N) {
			sum += arr[i + 1] + arr[i + 2];
			i = i + 3;
			continue;
		}

	}

	cout << sum;

}