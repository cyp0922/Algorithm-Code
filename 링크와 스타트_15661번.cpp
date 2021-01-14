#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int arr[21][21];
int visited[21];

int MIN = 987654321;

void func(int x,int cnt) {
	
	if (cnt == N / 2) {

		vector<int> start;
		vector<int> link;

		for (int i = 1; i <= N; i++) {
			if (visited[i]) {
				cout << i << " ";
			}
		}
		cout << endl;

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				cout << i << " ";
			}
		}
		cout << endl;
		cout << endl;


		for (int i = 1; i <= N; i++) {
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}

		int start_sum = 0;
		int link_sum = 0;

		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				if (start[j] != start[i]) {
					start_sum += arr[start[j]][start[i]];
				}
			}
		}

		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				if (link[j] != link[i]) {
					link_sum += arr[link[i]][link[j]];
				}
			}
		}

		MIN = min(MIN, abs(link_sum-start_sum));

	}

	for (int i = x + 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(i,cnt + 1);
			visited[i] = false;
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	func(0,0);

	cout << MIN;

}