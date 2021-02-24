#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

ll N, C, W;
int arr[51];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// C원 자르는 비용, W원 나무한단 팔때 , K개의 나무
	// 나무의 길이를 전부 같게 만들어, 나무를 파는 기회는 1번
	// k개의 나무, 길이가 L이면 K*L*W
	// N은 50보다 작거나같은 자연수, C,W는 10000보다 작거나 같은 자연수
	cin >> N >> C >> W;

	ll tall = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > tall) tall = arr[i];
	}

	ll MAX = 0;
	ll temp = 0;
	ll sum = 0;
	for (ll i = 1; i <= tall; i++) {
		temp = 0;
		sum = 0;
		for (ll j = 0; j < N; j++) {

			if (arr[j] == i) temp += W * i; //나무를 안자르는경우
			
			if (arr[j] % i == 0 && i * W * (arr[j] / i) >= C * (arr[j] / i - 1)) {
				sum +=  ( i * W * (arr[j] / i) - C * (arr[j] / i - 1) );
			}
			else if(arr[j] % i != 0 && i * W * (arr[j] / i) >= C * (arr[j] / i)){
				sum += ( i * W * (arr[j] / i) - C * (arr[j] / i) );
			}
		}

		MAX = max(MAX, max(sum, temp));
	}

	cout << MAX;


}