#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool arr[100001];
int B, K, N;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0); 

	// 26마리 52개 점

	cin >> N >> K >> B; // 횡단 번호, 연속K개 ,고장 난 번호

	int input;
	for (int i = 1; i <=B; i++) {
		cin >> input;
		arr[input] = true;
	}

	int MAX = 0;
	int cnt = 0;

	for (int i = 1; i <=N - K +1 ; i++) {

		cnt = 0;

		for (int j = i; j < i + K; j++) {
			if (arr[j]==0) cnt++;
		}

		MAX = max(MAX, cnt); 

	}

	cout << K- MAX;

}