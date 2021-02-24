#include<iostream>
#include<cmath>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	int test;
	cin >> test; 

	for (int t = 0; t < test; t++) {

		int x1, x2, y1, y2, n;
		int cx, cy, r;
		
		int cnt = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			
			float temp = sqrt(pow(abs(cx - x1), 2) + pow(abs(cy - y1), 2));
			float temp2 = sqrt(pow(abs(cx - x2), 2) + pow(abs(cy - y2), 2));
			if (temp < r && temp2 < r) continue;
			if (temp < r) cnt++;
			if (temp2 < r) cnt++;
		}

		cout << cnt << endl;

	}


}