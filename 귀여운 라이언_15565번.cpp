#include<iostream>
#include<algorithm>
using namespace std;

int N,K;
int dp[1000001];
bool arr[1000001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//���̾� ���� 1, ����ġ ���� 2
	//���̾� ������ K��

	cin >> N >> K;
	
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		if (input == 1) arr[i] = 1; // ���̾��϶�
		else arr[i] = 0; // 
	}
	
	int sum = 0;
	int MIN = 987654321;
	int idx = 0;

	for (int i = 1; i <= N; i++) {
	
		if (arr[i]) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];

		if (dp[i] - dp[idx] >= K) {

			while (idx < i ) {

				MIN = min(MIN, i - idx);
				idx++;

				if (dp[i] - dp[idx] < K) {
					break;
				}
			}
		}
	}

	if (MIN == 987654321) cout << "-1";
	else cout << MIN;

}