#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std; 

int N, M;
int map[701];
int in[4];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;
	int input;
	int pos = 0;

	for (int i = 0; i < 2*M -1; i++) map[i] = 1;

	for (int k = 1; k <= N; k++) {

		cin >> in[0] >> in[1] >> in[2];
		
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < in[i]; j++) {
				map[cnt] += i;
				cnt++;
			}
		}
	}

	for (int i = M - 1; i < 2 * M -1; i++) cout << map[i] << " ";
	cout << "\n";
	for (int i = M - 2; i >= 0; i--) {
		cout << map[i] << " ";
		for (int j = M; j < 2 * M -1; j++) cout << map[j] << " ";
		cout << "\n";
	}
}