#include<iostream>
#include<vector>
using namespace std;

int n;
long long k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �����̴� ���簢, �����̸� �ڸ� ���� �� ���� �����ϰ� �ڸ���.
	// �ڸ��� ����������, ��� ���� ��� �����̸� �ڸ� �� ���� �������ʴ´�.
	// �̹� �ڸ� ���� �ڸ� ������. 

	// n���� ������, k���� ������ ����
	cin >> n >> k;

	// ���ο� ����

	long long l = 0;
	long long r = n / 2;
	long long mid = (l + r) / 2;
	int cnt = 0;
	bool flag = false;
	while (l <= r && cnt < 2) {

		mid = (l + r) / 2;

		if ((mid + 1) * (n - mid + 1) < k) {
			l = mid + 1;
		}
		else {
			r = mid;
		}

		if (l == r) {
			cnt++;
		}

	}

	if ((mid + 1) * (n - mid + 1) == k) cout << "YES";
	else cout << "NO";

}