#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

ll N, C, W;
int arr[51];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// C�� �ڸ��� ���, W�� �����Ѵ� �ȶ� , K���� ����
	// ������ ���̸� ���� ���� �����, ������ �Ĵ� ��ȸ�� 1��
	// k���� ����, ���̰� L�̸� K*L*W
	// N�� 50���� �۰ų����� �ڿ���, C,W�� 10000���� �۰ų� ���� �ڿ���
	cin >> N >> C >> W;

	ll tall = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > tall) tall = arr[i];
	}

	ll MAX = 0;
	ll temp = 0;
	ll sum = 0;
	for (ll i = 1; i <= tall; i++) {
		temp = 0;
		sum = 0;
		for (ll j = 0; j < N; j++) {

			if (arr[j] == i) temp += W * i; //������ ���ڸ��°��
			
			if (arr[j] % i == 0 && i * W * (arr[j] / i) >= C * (arr[j] / i - 1)) {
				sum +=  ( i * W * (arr[j] / i) - C * (arr[j] / i - 1) );
			}
			else if(arr[j] % i != 0 && i * W * (arr[j] / i) >= C * (arr[j] / i)){
				sum += ( i * W * (arr[j] / i) - C * (arr[j] / i) );
			}
		}

		MAX = max(MAX, max(sum, temp));
	}

	cout << MAX;


}