#include<iostream>
#include<cmath>
using namespace std;

int N, A, B, C;
int arr[1000001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// N���� ������ , ������ �����帶�� �����ڵ��� �ִ�. Ai��
	// �Ѱ������� �� �����忡�� ������ �� �ִ� �������� ���� B��
	// �ΰ������� �� �����忡�� ������ �� �ִ� ������ ���� C��
	// ������ �����忡 �Ѱ������� ���� 1�� �־�� �ϰ� �� �������� ������ �־�ȴ�. 


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