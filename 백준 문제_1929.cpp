#include<iostream>
using namespace std;

int N, M;
bool arr[1000001];

int main() {

	// 에라토스테네스의 체의 식을 사용하면된다.
	// 자꾸 91퍼쯤에서 틀려서 뭐가 문제인가했는데 1로 시작하면 1이 출력되서 틀렸었다. 조심

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	arr[1] = true;

	for (int i = 2; i*i <= M; i++) {
			if (!arr[i]) {
				for (int j = i * i; j <= M; j += i) arr[j] = true;
			}
	}

	for (int i = N; i <= M; i++) {
		if (!arr[i]) cout << i << "\n";
	}

	
}
