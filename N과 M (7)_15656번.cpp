#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[8];
vector<int> v;

void func(int cnt) {
	
	if (cnt == M) {
		
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}
	
	for (int i = 1; i <= N; i++) {
		v.push_back(arr[i]);
		func(cnt + 1);
		v.pop_back();
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N + 1);

	func(0);

}