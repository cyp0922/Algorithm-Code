#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[9];
bool visited[9];
vector<int> v;
int N, M;

void func(int cnt) {
	
	if (cnt == M ) {

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}

	int temp = 0;
	if (!v.empty()) temp = v.back();

	for (int i = 1; i <= N; i++) {
		if (!visited[i] &&  temp < arr[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			func(cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
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