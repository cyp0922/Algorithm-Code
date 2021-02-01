#include<iostream>
#include<cmath>

using namespace std;

int n, r, c;

long long ans = 0;

// 범위계산 잘하자 ,,,

void func(int y, int x,int cnt) {

	if (cnt == 0) return;

	long long full = pow(2, cnt) ;
	long long half = pow(2, cnt - 1);

	if (0 <= y && y < half && 0 <= x && x < half) { // 1사분면
		ans += 0;
		func(y, x, cnt - 1);
	}
	else if (0 <= y && y < half && x < full && x >= half) { //2사분면
		ans += full * full / 4;
		func(y, x - pow(2, cnt - 1), cnt - 1);
	}
	else if (full > y && y >= half && 0 <= x && x < half) { //3사분면
		ans += 2 * full * full / 4;
		func(y - pow(2, cnt - 1), x , cnt - 1);
	}
	else if (full > y && y >= half && full > x && x >= half) { //4사분면
		ans += 3 * full * full / 4;
		func(y - pow(2, cnt - 1), x - pow(2, cnt - 1), cnt - 1);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> c;

	func(r, c, n);

	cout << ans;
}