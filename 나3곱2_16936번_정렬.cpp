#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool cmp(pair<long long,int> a, pair<long long,int> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int N;
	long long input;
	vector<pair<long long, int>> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back({ input,0 });

		int cnt = 0;
		while (true) {
			if (input % 3 == 0) {
				input = input / 3;
				cnt++;
			}
			else break;
		}

		v[i].second = cnt;

	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}

}