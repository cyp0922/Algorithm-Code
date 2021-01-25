#include<iostream>

using namespace std;

int gcd(int a, int b) {

	if (a == 0 || b == 0) return a + b;
	
	return b ==0 ? a : gcd(b, a % b);
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;

	x = abs(x);
	y = abs(y);

	if (x == 0 && y == 0) cout << "0";
	else if (gcd(x, y) == 1) cout << "1";
	else cout << "2";
	

}