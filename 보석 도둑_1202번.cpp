#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;

multiset<int> arr;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> je;

int N, K;

bool cmp(pair<int, int> a, pair<int, int> b) {

	if (a.first == b.first) {
		a.second < b.second;
	}
	return a.first > b.first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//cin >> N >> K;
	//int m, v, c;
	//for (int i = 0; i < N; i++) {
	//	cin >> m >> v; // 무게 가격
	//	je.push_back({ v,m }); //가격 무게
	//}
	//for (int i = 0; i < K; i++) {
	//	cin >> c;
	//	arr.insert(c);
	//}

	//sort(je.begin(), je.end(), cmp);

	//long long ans = 0; 
	//for (int i = 0; i < N; i++) {

	//	int cost = je[i].first;
	//	int weight = je[i].second; 
	//	if (arr.lower_bound(weight) != arr.end()) {
	//		ans += cost;
	//		arr.erase(arr.lower_bound(weight));
	//	}
	//}

	//cout << ans;
	arr.insert(1);
	cout << *arr.lower_bound(50);

}