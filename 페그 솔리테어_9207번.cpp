#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int N;
char arr[5][9];
int MAX = 0;
int sum = 0;
vector<pair<int, int>> v;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void func(int cnt) {

	MAX = max(MAX, cnt);

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 9; x++) {
			if (arr[y][x] == 'o') {

				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					int ky = y + 2 * dy[i];
					int kx = x + 2 * dx[i];

					if (0 <= ny && ny < 5 && 0 <= nx && nx < 9 && 0 <= ky && ky < 5 && 0 <= kx && kx < 9) {
						if (arr[ny][nx] == 'o') {
							if (arr[ky][kx] == '.') {
								arr[y][x] = '.';
								arr[ky][kx] = 'o';
								arr[ny][nx] = '.';
								func(cnt + 1);
								arr[y][x] = 'o';
								arr[ky][kx] = '.';
								arr[ny][nx] = 'o';
							}
						}
					}
				}

			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int p = 0; p < N; p++) {

		string input;
		MAX = 0;
		sum = 0;
		
		for (int y = 0; y < 5; y++) {
			cin >> input;
			for (int x = 0; x < 9; x++) {
				arr[y][x] = input[x];
				if (arr[y][x] == 'o') sum++;
			}
		}
		func(0);
		cout << sum - MAX << " " << MAX << endl;
	}
}