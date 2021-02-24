#include<iostream>
#include<algorithm>
#include<cmath>

#define ll long long 

using namespace std;

int main() {

	double N, L, H, W;

	cin >> N >> L >> W >> H;

	double l = 0;
	double r = 1e9;
	double mid = (l + r) / 2;

	for (int i = 0; i < 10000; i++) {

		mid = (l + r) / 2;
		if ((ll)(L / mid) * (ll)(H / mid) * (ll)(W / mid) >= N) l = mid;
		else r = mid;
	}

	printf("%.9f", l);

}
