#include<iostream>
#include<vector>

using namespace std;

int N, M;
bool visited[9];
int arr[9];

void func(int cnt) {
	
	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		
		return;
	}


	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[cnt+1] = i;
			visited[i] = true;
			func(cnt + 1);
			visited[i] = false;
			
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	func(0);
}