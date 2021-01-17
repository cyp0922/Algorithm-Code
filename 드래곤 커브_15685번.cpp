#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N;
bool map[101][101];
int dx[] = { 1,0,-1,0 };  // ¿ì »ó ÁÂ ÇÏ 0 1 2 3
int dy[] = { 0,-1,0,1 };

void func(int y_, int x_, int dir, int step) {

	vector<int> v;
	vector<int> store;

	v.clear();
	store.clear();
	
	map[y_][x_] = true;
	v.push_back(dir);

	int y = y_;
	int x = x_;

	for (int k = 0; k <= step; k++) {

		for (int i = store.size(); i < v.size(); i++) {

			int temp = v[i];
			int nx = x + dx[temp];
			int ny = y + dy[temp];

			map[ny][nx] = true;

			y = ny;
			x = nx;
		}

		store.clear(); 

		for (int i = v.size()-1; i >= 0; i--) {
			int temp = v[i];
			store.push_back((temp + 1) % 4);
		}

		for (int i = 0; i < store.size(); i++) {
			int temp = store[i];
			v.push_back(temp);
		}
		

	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, d, g; // ÁÂÇ¥,½ÃÀÛ ¹æÇâ, ¼¼´ë
	// µå·¡°ï Ä¿ºê´Â ¼­·Î °ãÄ¥ ¼ö ÀÖ´Ù. 
	// 0 ¿ì 1 »ó 2 ÁÂ 3 ¿ì

	//3
	//3 3 0 1
	//4 2 1 3
	//4 2 2 1

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		func(y, x, d, g);
	}

	int sum = 0;

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 100; i++) {
			if (map[j][i]  && map[j+1][i] && map[j][i+1] && map[j+1][i+1] ) {
				sum++;
			}
		}
	}

	cout << sum;

}