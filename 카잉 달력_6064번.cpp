#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int gcd(int x, int y) {

	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N, x, y;
	int play;
	cin >> play;

	for (int t = 0; t < play; t++) {

		cin >> M >> N >> x >> y;

		int cnt = x;
		int temp = x % N;

		int MAX = lcm(M, N);

		while (true) {

			if (temp  == y % N) {
				cout << cnt << endl;
				break;
			}

			if (MAX <= cnt) {
				cout << "-1" << endl;
				break;
			}

			cnt += M;
			temp = (temp + M) % N;

		}
	}

}