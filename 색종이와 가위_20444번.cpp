#include<iostream>
#include<vector>
using namespace std;

int n;
long long k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 색종이는 직사각, 색종이를 자를 때는 한 변에 평행하게 자른다.
	// 자르기 시작했으면, 경로 상의 모든 색종이를 자를 때 까지 멈추지않는다.
	// 이미 자른 곳은 자를 수없다. 

	// n번의 가위질, k개의 색종이 조각
	cin >> n >> k;

	// 가로와 세로

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