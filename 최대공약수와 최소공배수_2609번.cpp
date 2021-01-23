#include<iostream>

using namespace std;

int gcd(int a, int b) {

	while (b > 0) {
		
		int temp = b;
		b = a % b;
		a = temp;
	
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b);

}