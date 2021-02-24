#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int func(long long A, long long B, long long mod) {

	int ret = 1;
	while (B > 0) {

		if (B % 2 == 1) {
			ret = (ret * A) % mod;
		}
		A = A * A % mod;
		B = B / 2;
	}

	return ret;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long A, B, C;

	//�ڿ��� A�� B�� ���� ���� �˰� �ʹ�.
	//�� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	// (A*B) % C  -> ( A % C * B % C ) % C  

	cin >> A >> B >> C;

	cout <<	func(A, B, C);

}