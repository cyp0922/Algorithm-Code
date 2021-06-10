#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int r, c, k;
int N, M;
int arr[101][101];
int num[101];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void R_func() {

	// 모든 행에 대해서 정렬
	int temp_M = M;
	for (int y = 1; y <= N; y++) {
		memset(num, false, sizeof(num));
		vector<pair<int, int>> v;
		for (int x = 1; x <= M; x++) {
			num[arr[y][x]]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (num[i] != 0) v.push_back({i, num[i]});	
			arr[y][i] = 0;
		}
		sort(v.begin(), v.end(), cmp); 

		int idx = 1;
		for (int i = 0; i < v.size(); i++) {
			arr[y][idx] = v[i].first;
			arr[y][idx + 1] = v[i].second;
			temp_M = max(temp_M, idx + 1);
			idx += 2;
		}
	}

	M = temp_M;
}

void C_func() {

	// 모든 열에 대해서 정렬
	int temp_N = N;
	for (int x = 1; x <= M; x++) {
		memset(num, false, sizeof(num));
		vector<pair<int, int>> v;
		for (int y = 1; y <= N; y++) {
			num[arr[y][x]]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (num[i] != 0) v.push_back({ i, num[i] });
			arr[i][x] = 0;
		}
		sort(v.begin(), v.end(), cmp);

		int idx = 1;
		for (int i = 0; i < v.size(); i++) {
			arr[idx][x] = v[i].first;
			arr[idx + 1][x] = v[i].second;
			temp_N = max(temp_N, idx + 1);
			idx += 2;
		}
	}
	N = temp_N;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> r >> c >> k;

	N = 3; M = 3;
	for (int y = 1; y <= 3; y++) {
		for (int x = 1; x <= 3; x++) {
			cin >> arr[y][x];
		}
	}

	for (int t = 0; t <= 100; t++) {
		
		if (arr[r][c] == k) {
			cout << t << endl;
			exit(0);
		}	
		if (N >= M) R_func();
		else C_func();
	}
	cout << -1;
}