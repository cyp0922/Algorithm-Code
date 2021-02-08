#include<iostream>
#include<algorithm>

using namespace std;

typedef struct fish_ {

	int dir;
	int y;
	int x;
	bool live;

}fish_;

typedef struct shark {
	int y;
	int x;
	int dir;
	int eat;

}shark;

int MAX = 0;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int arr[18][4][4];
fish_ fish[18][17];
shark s;

void move_fish(int cnt, int sy, int sx) {

	int y;
	int x;

	for (int i = 1; i <= 16; i++) {
	
		if (fish[cnt][i].live == true) {
			y = fish[cnt][i].y;
			x = fish[cnt][i].x;
			int d = fish[cnt][i].dir;
			int c = 0;
			bool flag = false;
			while (c < 7) {

				int ny = y + dy[fish[cnt][i].dir];
				int nx = x + dx[fish[cnt][i].dir];

				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !(nx == sx && ny == sy)) {

					fish_ temp;
					int cn;
					if (arr[cnt][ny][nx] != 0) {
						temp.y = fish[cnt][arr[cnt][ny][nx]].y;
						temp.x = fish[cnt][arr[cnt][ny][nx]].x;
						fish[cnt][arr[cnt][ny][nx]].y = fish[cnt][i].y;
						fish[cnt][arr[cnt][ny][nx]].x = fish[cnt][i].x;
						fish[cnt][i].y = temp.y;
						fish[cnt][i].x = temp.x;
					}
					else {
						fish[cnt][i].y = ny;
						fish[cnt][i].x = nx;
					}


					cn = arr[cnt][ny][nx];
					arr[cnt][ny][nx] = arr[cnt][y][x];
					arr[cnt][y][x] = cn;
					flag = true;
					break;
				}

				fish[cnt][i].dir = (fish[cnt][i].dir + 1) % 8;
				c++;
			}

			if(flag == false) fish[cnt][i].dir = d;
		}
	}
}

void func(int cnt) {

	shark temp;
	MAX = max(MAX, s.eat);

	int y = s.y;
	int x = s.x;
	int d = s.dir;

	memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
	memcpy(fish[cnt], fish[cnt - 1], sizeof(fish[cnt]));
	temp = s;

	for (int k = 1; k <= 3; k++) {

		int nx = x + k * dx[d];
		int ny = y + k * dy[d];

		if (arr[cnt][ny][nx] == 0) continue;

		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {

			s.eat += arr[cnt][ny][nx];
			s.x = nx; s.y = ny;
			s.dir = fish[cnt][arr[cnt][ny][nx]].dir;
			fish[cnt][arr[cnt][ny][nx]].live = false;
			arr[cnt][ny][nx] = 0;

			move_fish(cnt, s.y, s.x);

			func(cnt + 1);

			memcpy(arr[cnt], arr[cnt - 1], sizeof(arr[cnt]));
			memcpy(fish[cnt], fish[cnt - 1], sizeof(fish[cnt]));
			s = temp;

		}
		else continue;
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// x���ȣ  y ����ȣ
	// ��ȣ 1~ 16 ������ȣ x
	// ���� 8���� 
	// (0,0) ������ �ִ� ������� ����� ����
	// ������ ��ȣ�� ���� �������� ������� �̵�
	// �̵��� �� �ִ� ĭ�� ��ĭ�� �ٸ� ����Ⱑ �ִ� ĭ
	// �̵��� �� ���� ĭ�� �� �ְų�, ������ ��踦 �Ѵ�ĭ
	// �� ����� ������ �̵��� �� ���� ĭ�� ���Ҷ� ���� ������ �ݽð� 45�� ȸ��
	// �̵��� �� �ִ� ĭ�� ������ �̵� x
	// ����� �̵� �� ��� �̵� . �� ���� �������� ĭ�� �� ���v
	// �� ����Ⱑ �ִ� ĭ���� �̵��ϸ� ��, ����⸦ �԰� ������� ������ ������.
	// �̵��ϴ�  �߿� �������� ĭ�� ���ű⸦ �����ʴ´�. ����Ⱑ ���� ĭ���� �̵�  x
	// �� �̵��� �� �ִ� ĭ�� ������ ������ ��� �����ΰ���. 
	// ��� �̵� �� ����� �̵�

	int a, b;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> a >> b;
			arr[0][y][x] = a;
			fish[0][a].dir = b - 1;
			fish[0][a].y = y;
			fish[0][a].x = x;
			fish[0][a].live = true;
		}
	}

	s.x = 0;  s.y = 0;
	s.eat = arr[0][0][0];
	s.dir = fish[0][arr[0][0][0]].dir;
	fish[0][arr[0][0][0]].live = false;
	arr[0][0][0] = 0;

	move_fish(0, s.y, s.x);
	func(1);

	cout << MAX;
}