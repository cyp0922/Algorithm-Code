#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int arr[9];
vector<int> v;

int N, M;

void func(int x, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << arr[v[i]] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = x; i <= N; i++) {
		v.push_back(i);
		func(i, cnt + 1);
		v.pop_back();
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <=N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + N + 1);  // 정렬해도 앞 0은 사용은 안하기에 상관 x

	func(1,0);




}