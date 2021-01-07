#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[16][2];
bool visited[16];
int ans = 0;

void func(int x, int sum){

	if (x > N) {
		ans = max(ans, sum);
		return;
	}

	for (int i = x; i <= N; i++) {

		if (!visited[i]) {
			visited[i] = true;
			if(i + arr[i][0] - 1 > N) func(N + 1, sum);
			else func(i + arr[i][0], sum + arr[i][1]);
			visited[i] = false;
		}

	}

}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	cin >> N; 
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	func(1,0);

	cout << ans;

}