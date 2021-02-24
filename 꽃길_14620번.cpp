#include<iostream>
#include<algorithm>

using namespace std; 

int N;
int arr[11][11];
bool visited[11][11];
bool flag = false;
int MIN = 1e9;

int dx[] = { -1,1,0,0 }; 
int dy[] = { 0,0,1,-1 };

void func(int cnt) {

	if (cnt == 3) {
		int sum = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x]) {
					sum += arr[y][x];
				}
			}
		}

		MIN = min(MIN, sum);
		return;

	}

	int cmp[11][11];
	memcpy(cmp, visited, sizeof(cmp));
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (!visited[y][x]) {

				flag = false;
				visited[y][x] = true;

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] == 1) {
						memcpy(visited, cmp, sizeof(visited));
						flag = true;
						break;
					}

					visited[ny][nx] = true;

				}

				if (flag == false) {
					func(cnt + 1);
					memcpy(visited, cmp, sizeof(visited));
				}
			}
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N; 

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> arr[y][x];
		}
	}

	func(0);

	cout << MIN;

}