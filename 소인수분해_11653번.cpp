#include<iostream>
#include<vector>

using namespace std;

bool arr[10000001];
vector<int> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;

	arr[1] = true;
	for (int i = 2; i <= N; i++) {
		if (!arr[i]) {
			v.push_back(i);
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = true;
			}
		}
	}

	int idx = 0;
	while (N > 1) {

		if (N % v[idx] == 0) {
			cout << v[idx] << endl;
			N = N / v[idx];
		}
		else {
			idx++;
		}
	}
}