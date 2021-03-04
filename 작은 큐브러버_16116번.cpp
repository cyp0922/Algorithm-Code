#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

char arr[4][9][4];
char cmp[6] = { 'W','B','O','G','R','Y' };
int visited[7][9]; // W B O G R Y 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// À­¸é ¿ÞÂÊ¸é ¿À¸¥ÂÊ¸é

	for (int i = 0; i < 8; i++) {

		for(int j=0; j<3; j++){
			cin >> arr[0][i][j];
		}

		for (int k = 1; k <= 2; k++) {
			for (int m = 0; m < 3; m++) {
				arr[k][i][m] = arr[0][i][(m + k) % 3];
			}
		}
	}

	for (int k = 0; k < 6; k++) {

		vector<pair<char, char>> v;
		queue<char> q;
		int visited[4];
		memset(visited, false, sizeof(visited));

		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 3; b++) {
				if (arr[b][a][0] == cmp[k]) {
					v.push_back({ arr[b][a][1] , arr[b][a][2] });
				}
			}
		}

		q.push(v[0].first); q.push(v[0].second);

		for (int k = 0; k < 3; k++) {
			for (int i = 1; i < v.size(); i++) {
				if (!visited[i]) {
					if (q.back() == v[i].first) {
						q.push(v[i].first);
						q.push(v[i].second);
						visited[i] = true;
					}
				}
			}
		}

		if (q.size() != 8 || q.front() != q.back()) {
			cout << "NO";
			exit(0);
		}
	}

	cout << "YES";
}