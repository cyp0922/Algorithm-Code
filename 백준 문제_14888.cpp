#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[12];
int mul[4];
int MAX = -100000001, MIN = 1000000001;

void func(int x, int sum) {


	if ( x ==  N) {
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
		return;
	}

	// µ¡¼À –y¼À °ö¼À ³ª´°¼À
	for (int i = 0; i < 4; i++) {

		
		if (mul[i] > 0) {

			mul[i]--;
			int cmp = sum;
			if (i == 0) cmp += arr[x + 1];
			else if (i == 1) cmp -= arr[x + 1];
			else if (i == 2) cmp *= arr[x + 1];
			else if (i == 3) cmp /= arr[x + 1];
			func(x + 1, cmp);
			mul[i]++;
		}

	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) {
		cin >> mul[i];
	}

	func(1,arr[1]);

	cout << MAX << "\n" << MIN;

}