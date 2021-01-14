#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N;
char arr[10];
int visited[10];
string MIN = "9999999999"; 
string MAX = "0";

void func(int x, int cnt) {

	if (cnt == N+1) {

		string output;

		for (int i = 1; i <= N + 1; i++) {
			for (int j = 0; j <=9; j++) {
				if (visited[j] == i) output += to_string(j);
			}
		}

		long long x = stoll(output);
		long long MIN_s = stoll(MIN);
		long long MAX_s = stoll(MAX);

		MIN = MIN_s > x ? output : MIN;
		MAX = MAX_s < x ? output : MAX;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {

			visited[i] = cnt+1; 

			if(arr[cnt] == 'o') func(i, cnt + 1);
			if (arr[cnt] == '>' && x > i) {
				func(i, cnt + 1);
				
			}
			if (arr[cnt] == '<' && x < i) {
				func(i, cnt + 1);
			}
			visited[i] = false;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	arr[0] = 'o';
	for (int i = 1; i <=N; i++) cin >> arr[i];

	func(0,0);
	
	cout << MAX << "\n" << MIN;
}