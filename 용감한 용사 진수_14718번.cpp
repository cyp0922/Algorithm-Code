#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;

int arr[101][3];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �� ��ø ���� 
	// �����簡 ���� ������ ������ ���� ũ�ų� ����
	// �� ���簡 ���� ��ø���� ������ ��ø�� ũ�ų� ����
	// �� ���簡 ���� ���ɺ��� ������ ũ�ų� ������
	// ���縦 ���̱��

	// N���� ����, K���� ����

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