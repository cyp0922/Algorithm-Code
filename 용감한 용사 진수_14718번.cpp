#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;

int arr[101][3];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 힘 민첩 지능 
	// 적병사가 가진 힘보다 진수의 힘이 크거나 같다
	// 적 병사가 가진 민첩보다 진수의 민첩이 크거나 같고
	// 적 병사가 가진 지능보다 진수의 크거나 같으면
	// 병사를 못이긴다

	// N명의 병사, K명의 병사

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int MIN = 1e9;

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {

				int cnt = 0;

				for (int i = 1; i <= N; i++) {
					if (arr[a][0] >= arr[i][0] && arr[b][1] >= arr[i][1] && arr[c][2] >= arr[i][2]) {
						cnt++;
					}
				}
				
				if (cnt == K) {
					MIN = min(MIN, arr[a][0] + arr[b][1] + arr[c][2]); 
				}

			}
		}
	}
	
	cout << MIN;

}