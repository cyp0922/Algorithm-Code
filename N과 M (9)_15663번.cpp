#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;

vector<int> v;
int arr[10];
bool visited[10];

void func(int cnt) {


	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";

		return;
	}

	int cmp = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[i] != cmp) {
			cmp = arr[i];
			visited[i] = true;
			v.push_back(arr[i]);
			func(cnt + 1);
			visited[i] = false;
			v.pop_back();
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