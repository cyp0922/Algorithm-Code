#include<iostream>
#include<vector>

using namespace std;

int E, N, P;
int x, y;
int arr[21][2];
bool visited[21];
vector<int> v;

void func(int cnt, int s) {

	if (cnt == P) {

		int e = 0;
		for (int i = 0; i < v.size(); i++) {
			e += arr[v[i]][1];
		}

		if (s <= E && E <= e) {

			vector<int> store;
			int temp = E;

			for (int i = 0; i < v.size(); i++) {
				store.push_back(arr[v[i]][0]);
				E -= arr[v[i]][0];
			}

			for (int i = 0; i < store.size(); i++) {
	
				if (E <= 0) break;

				if (arr[v[i]][1] - store[i] <= E) {
					E -= (arr[v[i]][1] - store[i]);
					store[i] = arr[v[i]][1];
				}
				else {
					store[i] += E;
					E = 0;
				}	
			}

			int idx = 0;
			for (int i = 1; i <= N; i++) {
				if (visited[i]) {
					cout << store[idx] << " ";
					idx++;
				}
				else cout << "0 ";
			}
			exit(0);

		}
		return;
	}

	int temp = 0;
	if (v.size() != 0) temp = v.back();

	for (int i = temp +1 ; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			func(cnt + 1, s + arr[i][0]);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> P >> E; // 러버덕 인형, 러사모 회원, 
	// xi 개 이상 yi개 이하

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	func(0, 0);

	cout << "-1";

}