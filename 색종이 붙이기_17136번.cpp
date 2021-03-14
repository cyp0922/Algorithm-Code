#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 52Ка

int arr[11][11];
bool visited[11][11];
int kind[5] = { 0,1,2,3,4 };
int kind_cnt[5] = { 5,5,5,5,5 };
int all = 0;
int MIN = 1e9;

void func(int cnt, int use) {

	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {

			if (arr[y][x] == 1 && !visited[y][x]) {

				for (int i = 0; i < 5; i++) {

					int ny = y + kind[i];
					int nx = x + kind[i];

					int num = 0;

					for (int ky = y; ky <= ny; ky++) {
						for (int kx = x; kx <= nx; kx++) {
							if (arr[ky][kx] == 1 && !visited[ky][kx]) {
								num++;
							}
						}
					}

					if (num == (kind[i] + 1) * (kind[i] + 1) ) {

						if (kind_cnt[i] == 0) continue;
						kind_cnt[i]--;

						for (int ky = y; ky <= ny; ky++) {
							for (int kx = x; kx <= nx; kx++) {
								visited[ky][kx] = true;
							}
						}

						if (cnt + num == all) {
							MIN = min(MIN, use + 1);
						}
						else func(cnt + num, use + 1);

						kind_cnt[i]++;

						for (int ky = y; ky <= ny; ky++) {
							for (int kx = x; kx <= nx; kx++) {
								visited[ky][kx] = false;
							}
						}
					}
					else break;
				}
				return;
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int y = 1; y <= 10; y++) {
		for (int x = 1; x <= 10; x++) {
			cin >> arr[y][x];
			if(arr[y][x] == 1) all++;
		}
	}

	func(0,0);

	if (all == 0) cout << "0";
	else if (MIN == 1e9) cout << "-1";
	else cout << MIN;

}