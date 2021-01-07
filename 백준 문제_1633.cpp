#include<iostream>
#include<vector>

using namespace std;

bool arr[4000001];
vector<int> store;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N == 1) {
		cout << "0";
		return 0;
	}

	for (int i = 2; i * i <= N; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= N; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!arr[i]) store.push_back(i);
	}

	long long sum = 0;
	int cnt = 0;
	int s = 0;
	int d = 0;

	while(1){
		
		if (sum <= N) {
			sum += store[s];
			if (store.size()-1 > s) s++;
		}

		if (sum > N) {
			sum -= store[d];
			if (store.size() - 1 > d) d++;
		}
		
		if (sum == N) cnt++;
	
		if (s == store.size() - 1 && d == store.size() - 1) break;
	}

	cout << cnt;

}