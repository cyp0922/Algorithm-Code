#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int T;
long long x, y;

int MIN;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	for (int p = 0; p < T; p++) {

		cin >> x >> y; 
		
		long long diff = y - x;
		
		int n = sqrt(diff);

		long long cmp = diff - pow(n, 2);
		
		if (cmp == 0) cout << n * 2 - 1 << endl;
		else if (cmp > 0 && cmp <= n) cout << n * 2 << endl;
		else cout << n * 2 + 1 << endl;

	}

	
}
