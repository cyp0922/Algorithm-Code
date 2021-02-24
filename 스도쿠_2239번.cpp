#include<iostream>
#include<vector>
using namespace std;


vector< pair<int, int> > v;


int arr[9][9];

bool check(int a, int b, int cnt) {

	for (int y = 3 * (a / 3); y < 3 * (a / 3 + 1); y++) {
		for (int x = 3 * (b / 3); x < 3 * (b / 3 + 1); x++) {
			if (y == a && x == b) continue;
			if (arr[y][x] == cnt) return 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		if ((i != a && arr[i][b] == cnt) || (i != b && arr[a][i] == cnt )) return  0;
	}

	return 1;

}

void func(int x) {

	if (x == v.size()) {

		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				printf("%d", arr[y][x]);
			}
			cout << "\n";
		}
		exit(0);
	}


	for (int i = 1; i <= 9; i++) {
		
		arr[v[x].first][v[x].second] = i;
		if (check(v[x].first, v[x].second, i)) {
			func(x + 1);
		}
		arr[v[x].first][v[x].second] = 0;
	}

}

int main() {

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}
	
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (arr[y][x] == 0) v.push_back({ y,x });
		}
	}

	func(0);

}