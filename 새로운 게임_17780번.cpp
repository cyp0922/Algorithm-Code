// 3¹ø½Ãµµ 45ºÐ

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std; 

int N, K;
int map[13][13];
deque<int> arr[13][13];

int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int rdir[] = { 1,0,3,2 };

struct is {
	int y;
	int x;
	int dir;
	int cnt;
};
is horse[11];

void play() {

	for (int p = 1; p <= 1000; p++) {

		for (int h = 1; h <= K; h++) {

			int y = horse[h].y;
			int x = horse[h].x;
			int cnt = horse[h].cnt;
			int dir = horse[h].dir;

			if (cnt == 1) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
					if (map[ny][nx] == 0) { //Èò»ö

						int as = arr[y][x].size();
						int ts = arr[ny][nx].size() + 1;
						for (int i = 0; i < as; i++) {
							arr[ny][nx].push_back(arr[y][x].front());
							horse[arr[y][x].front()].y = ny;
							horse[arr[y][x].front()].x = nx;
							horse[arr[y][x].front()].cnt = ts;
							arr[y][x].pop_front();
							ts++;
						}
					}
					else if (map[ny][nx] == 1) {
						int as = arr[y][x].size();
						int ts = arr[ny][nx].size() + 1;
						for (int i = 0; i < as; i++) {
							arr[ny][nx].push_back(arr[y][x].back());
							horse[arr[y][x].back()].y = ny;
							horse[arr[y][x].back()].x = nx;
							horse[arr[y][x].back()].cnt = ts;
							arr[y][x].pop_back();
							ts++;
						}
					}
					else if (map[ny][nx] == 2) {

						ny = y + dy[rdir[dir]];
						nx = x + dx[rdir[dir]];
						horse[h].dir = rdir[dir];
						if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
							if (map[ny][nx] != 2) {
								if (map[ny][nx] == 0) {
									int as = arr[y][x].size();
									int ts = arr[ny][nx].size() + 1;
									for (int i = 0; i < as; i++) {
										arr[ny][nx].push_back(arr[y][x].front());
										horse[arr[y][x].front()].y = ny;
										horse[arr[y][x].front()].x = nx;
										horse[arr[y][x].front()].cnt = ts;
										arr[y][x].pop_front();
										ts++;
									}
								}
								else if (map[ny][nx] == 1) {
									int as = arr[y][x].size();
									int ts = arr[ny][nx].size() + 1;
									for (int i = 0; i < as; i++) {
										arr[ny][nx].push_back(arr[y][x].back());
										horse[arr[y][x].back()].y = ny;
										horse[arr[y][x].back()].x = nx;
										horse[arr[y][x].back()].cnt = ts;
										arr[y][x].pop_back();
										ts++;
									}
								}
							}
						}
					}
				}
				else {// ÆÄ¶û
					ny = y + dy[rdir[dir]];
					nx = x + dx[rdir[dir]];
					horse[h].dir = rdir[dir];
					if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
						if (map[ny][nx] != 2) {
							if (map[ny][nx] == 0) {
								int as = arr[y][x].size();
								int ts = arr[ny][nx].size() + 1;
								for (int i = 0; i < as; i++) {
									arr[ny][nx].push_back(arr[y][x].front());
									horse[arr[y][x].front()].y = ny;
									horse[arr[y][x].front()].x = nx;
									horse[arr[y][x].front()].cnt = ts;
									arr[y][x].pop_front();
									ts++;
								}
							}
							else if (map[ny][nx] == 1) {
								int as = arr[y][x].size();
								int ts = arr[ny][nx].size() + 1;
								for (int i = 0; i < as; i++) {
									arr[ny][nx].push_back(arr[y][x].back());
									horse[arr[y][x].back()].y = ny;
									horse[arr[y][x].back()].x = nx;
									horse[arr[y][x].back()].cnt = ts;
									arr[y][x].pop_back();
									ts++;
								}
							}
						}
					}
				}
			}
		}
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (arr[y][x].size() >= 4) {
					cout << p; 
					return;
				}
			}
		}		
	}
	cout << "-1";

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x]; 
		}
	}

	int a, b, c;
	for (int i = 1; i <= K; i++) {
		cin >> b >> a >> c;
		horse[i] = { b,a,c - 1,1};
		arr[b][a].push_back(i);
	}
	play();
}
