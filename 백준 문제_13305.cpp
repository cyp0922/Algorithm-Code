#include<iostream>

using namespace std;

int N;
int city[100001];
int dis[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 1km 마다 1리터
	
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> dis[i];
	
	for (int i = 0; i < N; i++) cin >> city[i];
	

	long long sum = 0; // 총 가격 1,000,000,000이 넘으므로 단위 조심
	int k = 0;
	int distance = 0;

	for (int i = 1; i < N; i++) {
		
		distance += dis[i - 1];

		if (city[k] <= city[i] ){
			if(i != N-1) continue;
		}

		sum += (long long)city[k] * distance; 
		k = i;
		distance = 0;

	}

	cout << sum;


}