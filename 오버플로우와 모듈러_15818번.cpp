#include<iostream>

using namespace std;

int arr[101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	// N���� ������ ���Ѵ�. 
	// N���� ������ M�� �־��� ��, ��� ������ ���� M���� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

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