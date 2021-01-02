#include<iostream>
using namespace std;

int N, M;
bool arr[1000001];

int main() {

	// �����佺�׳׽��� ü�� ���� ����ϸ�ȴ�.
	// �ڲ� 91���뿡�� Ʋ���� ���� �����ΰ��ߴµ� 1�� �����ϸ� 1�� ��µǼ� Ʋ�Ⱦ���. ����

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	arr[1] = true;

	for (int i = 2; i*i <= M; i++) {
			if (!arr[i]) {
				for (int j = i * i; j <= M; j += i) arr[j] = true;
			}
	}

	for (int i = N; i <= M; i++) {
		if (!arr[i]) cout << i << "\n";
	}

	
}
