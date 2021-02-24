#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
vector<pair<int, int>> v;
int store[1000001];
int MAX = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {

	return a.second < b.second;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// n <= 100000, xi <= 1000000 gi 10000  좌우 k 2000000

	cin >> N >> K;

	int a, b;
	int last = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b; // 얼음의 양, 양동이 좌표
		store[b] = a;
		last = max(last, b);
	}


	int sum = 0;
	for (int i = 0; i <= K; i++) {
		if( i <= last ) sum += store[i]; // 좌표 0기준
	}
	MAX = sum;

	for (int i = 1; i <= last; i++) {

		if (i - K - 1 >=0) sum -= store[i - K - 1];
		if (i + K <= last) sum += store[i + K];
		MAX = max(sum, MAX);

	}

	cout << MAX;



}