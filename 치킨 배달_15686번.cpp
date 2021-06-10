#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[51][51];
int MIN = 1e9;

struct is {
	int y;
	int x;
};

vector<is> chi;
vector<is> live;
vector<is> home;

void func(int x, int cnt) {

	if (cnt > 0 && cnt <= M) {

		int sum = 0;
		for (int j = 0; j < home.size(); j++) {
			int cmp = 1e9;
			for (int i = 0; i < live.size(); i++) {
				cmp = min(cmp, abs(home[j].y - live[i].y) + abs(home[j].x - live[i].x));
			}
			sum += cmp;
		}

		MIN = min(MIN, sum);
	}
	else if (cnt > M) return;

	for (int i = x; i < chi.size(); i++) {		
		live.push_back({ chi[i].y , chi[i].x });
		func(i + 1, cnt + 1);
		live.pop_back();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 1) home.push_back({ y,x });		
			if (arr[y][x] == 2) chi.push_back({ y,x });		
		}
	}

	func(0,0);

	cout << MIN << endl;
}