// 1시간
#include<iostream>
#include<vector>
using namespace std;

int N;
int arr[102][102];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int tx[] = { 1,1,0 };
int ty[] = { 0,1,1 };
int square = 0;

struct dra {
	int y;
	int x;
	int d;
	int g;
};

vector<dra> dragon;

void func(int cnt) {

	vector<int> v;

	int y = dragon[cnt].y;
	int x = dragon[cnt].x;
	int d = dragon[cnt].d;
	int g = dragon[cnt].g;

	v.push_back(d);
	arr[y][x] = cnt + 1;
	arr[y + dy[d]][x + dx[d]] = cnt + 1;
	y = y + dy[d]; 
	x = x + dx[d];

	for (int i = 1; i <= g; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			int d = (v[j] + 1) % 4;
			//if (d < 0) d = 3;

			int ny = y + dy[d];
			int nx = x + dx[d];
			arr[ny][nx] = cnt+1;
			v.push_back(d);
			y = ny; 
			x = nx;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 0우 1상 2좌 3하

	cin >> N;
	int cy, cx, cd, cg;
	for (int i = 0; i < N; i++) {
		cin >> cx >> cy >> cd >> cg;
		dragon.push_back({ cy,cx,cd,cg });
	}

	for (int i = 0; i < N; i++) {
		func(i);
	}

	int num = 0;
	for (int y = 0; y <= 99; y++) {
		for (int x = 0; x <= 99; x++) {
			if (arr[y][x]) {
				num = 0;
				for (int i = 0; i < 3; i++) {
					int ny = y + ty[i];
					int nx = x + tx[i];
					if (arr[ny][nx]) num++;
				}

				if (num == 3) square++;
			}
		}
	}
	cout << square;
}