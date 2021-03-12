#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N;
string input;
int MAX = -2e9;

int change(int a, int b, char cmp) {

	if (cmp == '+') return a + b;
	else if (cmp == '-') return a - b;
	else if (cmp == '*') return a * b;
	else if (cmp == '/') return a / b;

}

void dfs( int idx, int sum ) {

	cout << idx << " " << sum << endl;

	if (idx >= input.size() - 1) {
		MAX = max(MAX, sum);
		return;
	}

	// °ıÈ£ Àû¿ë

	if (idx < input.size() - 3) {
		dfs(idx + 4, change(sum, change(input[idx + 2] - '0', input[idx + 4] - '0', input[idx + 3]), input[idx + 1]));
	}
	dfs(idx + 2, change(sum, input[idx + 2] - '0', input[idx + 1]));

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> input;

	dfs(0, input[0]-'0');

	cout << MAX;

}