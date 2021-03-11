#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int die[11];
int horse[5];
bool live[5];
int MAX = 0;
int map[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,10,13,16,19,25,30,28,27,26,25,20,22,24,25,30,35,40,0 };
bool visited[40];

int change(int cnt, int plus) {
	// 20 - (40)
	// 왼 21 ~ 25
	// 오 26 ~ 30
	// 가 31 ~ 33
	// 34 - (25)

	int all = cnt + plus;

	if (cnt >= 0 && cnt <= 20) {
		if (all == 5) return 21;
		else if (all == 10) return 31;
		else if (all == 15) return 26;
		else if (all == 20) return 37;
		else if (all > 20) return 38;
		else return all;
	}
	else if (cnt >= 21 && cnt <= 25) { // 왼쪽 벗어날때
		if (all == 25) return 34;
		else if (all > 25) return 34 + all - 25;
		else return all;
	}
	else if (cnt >= 26 && cnt <= 30) { // 오른쪽
		if (all == 30) return 34;
		else if (all > 30) return 34 + all - 30;
		else return all;
	}
	else if (cnt >= 31 && cnt <= 37) { // 오른쪽
		if (all > 37) return 38;
		else return all;
	}
	else return 38;
}

void dfs(int cnt, int sum) {

	if (cnt == 11) {
		MAX = max(sum, MAX);
		return;
	}

	int jump = die[cnt];

	for (int i = 1; i <= 4; i++) {

		if (!live[i]) {
			int cur = horse[i];
			int move = change(cur, jump);
			if ( move >= 38 || !visited[move]) {

				if (move >= 38) {
					live[i] = true;
					visited[cur] = false;
					dfs(cnt + 1, sum);
					visited[cur] = true;
					live[i] = false;
				}
				else {
					horse[i] = move;
					visited[cur] = false;
					visited[move] = true;
					//cout << cnt << " " << map[move] << " " << i << endl;
					dfs(cnt + 1, sum + map[move]);
					visited[move] = false;
					visited[cur] = true;
					horse[i] = cur;
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 주사위에서 나올 수 10개
	// 20 - (40) 
	// 왼 21 ~ 25
	// 오 26 ~ 30
	// 가 31 ~ 33
	// 34 - (25)

	for (int i = 1; i <= 10; i++) cin >> die[i];
	dfs(1, 0);
	cout << MAX;
}