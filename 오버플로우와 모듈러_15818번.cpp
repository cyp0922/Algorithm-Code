#include<iostream>

using namespace std;

int arr[101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	// N개의 정수를 곱한다. 
	// N개의 정수와 M이 주어질 때, 모든 정수의 곱을 M으로 나눈 나머지를 계산하는 프로그램을 작성하시오

	int N, M;
	
	cin >> N >> M; 

	for (int i = 1; i <= N; i++) {
		cin >> arr[i]; 
	}

	long long temp = 1;

	for (int i = 1; i <= N; i++) {
		temp *= arr[i] % M;
		temp = temp % M;
	}

	cout << temp;

}