#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
int arr[14];
int temp[7];
int visited[14];

void func(int x) {
	
	if (x == 6) {
		for (int i = 1; i <= 6; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = x+1; i <= N; i++) {
		if ( arr[i] > temp[x] )  {
			temp[x+1] = arr[i];
			func(x + 1);
		}
	}
	
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	do{
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> arr[i];

		func(0);
		cout << "\n";

		memset(arr, 0, sizeof(arr));
		
	} while (N != 0);

}