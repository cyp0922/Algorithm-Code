#include<iostream>

using namespace std;

int N;
char arr[51][51];
bool visited[51][51];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int max(int a, int b) {
	return a > b ? a : b;
}

int func(int y,int x) {

	int cmp = 0;

	for (int i = 0; i < 2; i++) { // »óÇÏ, ÁÂ¿ì
		
		int cnt = 1;
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		int h_x = x + dx[(i + 2) % 4];
		int h_y = y + dy[(i + 2) % 4];

		while(arr[y][x] == arr[n_y][n_x] )
		{
			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
				if (arr[n_y][n_x] == arr[y][x]) {
						cnt++;
				}
			}
			n_x += dx[i];
			n_y += dy[i];
		}

		while (arr[y][x] == arr[h_y][h_x]){

			if (h_x >= 0 && h_x < N && h_y >= 0 && h_y < N) {
				if (arr[h_y][h_x] == arr[y][x]) {
					cnt++;
				}
			}
			h_x += dx[(i + 2) % 4];
			h_y += dy[(i + 2) % 4];
		}

		cmp = max(cnt, cmp);

	}
	return cmp;
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

	int MAX =0 ;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			for (int i = 0; i < 4; i++) {

				int n_x = x + dx[i];
				int n_y = y + dy[i];

				if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
					
					int temp = arr[y][x];
					arr[y][x] = arr[n_y][n_x];
					arr[n_y][n_x] = temp;

					MAX = max(MAX, func(y, x));
					
					temp = arr[n_y][n_x]; 
					arr[n_y][n_x] = arr[y][x];
					arr[y][x] = temp;
				}
			}
		}
	}

	cout << MAX;

}