#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, D; 
int map[16][15];
int cmp[16][15];

typedef struct em {
	bool live = true;
	int y;
	int x;
	int hit = 0;
	int dis;
}em;

vector< pair<int,int> > hunter;
vector<em> wjr;
int MAX = 0;

bool compare( em a, em b ) {

	if (a.dis == b.dis) {
		return a.x < b.x;
	}

	return a.dis < b.dis;

}

void func(int x, int cnt) {

	if (cnt == 3) {

		vector<em> v;
		v.assign(wjr.begin(), wjr.end());
		int kill = 0;

		while (true) {

			for (int k = 0; k < 3; k++) {
				
				for (int i = 0; i < v.size(); i++) {
					v[i].dis = 1e9;
					if (v[i].live) {
						v[i].dis = abs(hunter[k].first - v[i].y) + abs(hunter[k].second - v[i].x);
					}
				}
				sort(v.begin(), v.end(), compare);

				if (v[0].dis <= D) { // �� ����
					v[0].hit++;
				}
			}

			int num = 0;

			for (int i = 0; i < v.size(); i++) {

				if (v[i].hit > 0 && v[i].live) {
					v[i].live = false;
					kill++;
				}
				
				if (v[i].live) {
					v[i].y++;
					if (v[i].y >= N) v[i].live = false;
				}
				
				if (v[i].live == false) num++;

			}

			if (num == v.size()) break;
		}

		MAX = max(MAX, kill);
		return;
	}


	for (int i = x + 1; i < M; i++) {

		hunter.push_back({ N,i });
		func(i, cnt + 1); 
		hunter.pop_back();
	
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// �ü� 3�� �Ÿ� D���� ��
	// ���� ������ ���� ����
	// �� ���� ���� �ü����� ���� ���� �� �ִ�.
	// �ü��� �������� ������ �� �ִ� ���� �ִ� �� 

	cin >> N >> M >> D;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++ ) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				wjr.push_back({ true,y,x,0 });
			}
		}
	}

	func(-1,0);

	cout << MAX;

}