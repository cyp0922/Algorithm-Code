#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, K;

	cin >> N >> K; 

	//1 2 3 4 ..
	//2 4 6 8 ..
	//3 6 9 12 ..
	//4 8 12 16 ...

	long long l = 1;
	long long r = 1e10;
	long long mid = 0;
	long long cnt = 0;

	while (l <= r) {
		
		cnt = 0; 
		mid = (l + r) / 2;
		
		for (int i = 1; i <=N; i++) {
			cnt += min((long long)N, mid/i);
		}

		if (cnt < K) l = mid + 1;
		else r = mid - 1;

	}

	cout << l;


}