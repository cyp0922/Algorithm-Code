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

	//자연수 A를 B번 곱한 수를 알고 싶다.
	//단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

	// (A*B) % C  -> ( A % C * B % C ) % C  

	cin >> A >> B >> C;

	cout <<	func(A, B, C);

}