#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool arr[100001];
int B, K, N;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0); 

	// 26���� 52�� ��

	cin >> N >> K >> B; // Ⱦ�� ��ȣ, ����K�� ,���� �� ��ȣ

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