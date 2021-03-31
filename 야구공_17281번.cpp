// 1시간 10분

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N;
int idx = 0;
int arr[51][10];
bool visited[10];
int score = 0;
int MAX = 0;
bool ground[3];
vector<int> order;

void play(int cnt, int turn, int score) {

	if (turn == N) {
		MAX = max(MAX, score);
		return;
	}	

	memset(ground, false, sizeof(ground));
	int num = score;
	int out = 0;

	while (out != 3) {
		if (arr[turn][order[cnt]] == 0) out++;
		else if (arr[turn][order[cnt]] == 1) {
			for (int i = 2; i >= 0; i--) {
				if (i < 2 && ground[i] == true) {
					ground[i] = false;
					ground[i + 1] = true;
				}
				else if (i == 2 && ground[i] == true) {
					num++;
					ground[i] = false;
				}
			}
			ground[0] = true;
		}
		else if (arr[turn][order[cnt]] == 2) {
			for (int i = 2; i >= 0; i--) {
				if (ground[i] == true && i > 0) {
					num++;
					ground[i] = false;
				}
				else if (i == 0 && ground[i] == true) {
					ground[i] = false;
					ground[i + 2] = true;
				}
			}
			ground[1] = true;
		}
		else if (arr[turn][order[cnt]] == 3) {
			for (int i = 2; i >= 0; i--) {
				if (ground[i] == true) {
					num++;
					ground[i] = false;
				}
			}
			ground[2] = true;
		}
		else if (arr[turn][order[cnt]] == 4) {
			for (int i = 2; i >= 0; i--) {
				if (ground[i] == true) {
					num++;
					ground[i] = false;
				}
			}
			num++;
		}
		cnt++;
		if (cnt == 9) cnt = 0;
	}
	play(cnt, turn + 1, num);
}

void func(int cnt) {

	if (cnt == 9) {

		play(0, 0, 0);
		return; 
	}

	if (cnt == 3) {
		order.push_back(0);
		func(cnt + 1);
		order.pop_back();
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			order.push_back(i);
			func(cnt + 1); 
			order.pop_back();
			visited[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	// 아웃 0 , 안타 1, 2루타 2, 3루타 3,  홈런 4

	func(0);
	cout << MAX;
}