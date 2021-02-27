#include<iostream>
#include<cmath>
using namespace std;

int N, A, B, C;
int arr[1000001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// N개의 시험장 , 각각의 시험장마다 응시자들이 있다. Ai명
	// 총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명
	// 부감독관은 한 시험장에서 감시할 수 있는 응시자 수가 C명
	// 각각의 시험장에 총감독관은 오직 1명만 있어야 하고 부 감독관은 여러명 있어도된다. 


	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> B >> C;

	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		if (arr[i] - B > 0) cnt += (long long)ceil((float)(arr[i] - B) / (float)C);
	}

	cout << cnt;
}