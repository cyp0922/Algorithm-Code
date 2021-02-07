#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct item {

	int num = 0;
	char color = 'W';

}item;

item store[4][5][5];
item arr[10][4][4];
int n;
int	MAX = 0;
bool visited[10];
int dx[] = { 0,1,0,1 };
int dy[] = { 0,0,1,1 };

void func(int x);
void position(int cnt, int k);

void position(int cnt, int k) {

	item cmp[4][4];
	memcpy(store[cnt], store[cnt - 1], sizeof(store[cnt]));
	memcpy(cmp, arr[k], sizeof(cmp));

	int nx, ny;
	item copy[4][4];

	for (int a = 0; a < 4; a++) { // ȸ�� for��

		for (int y = 0; y < 4; y++) { // ȸ��
			for (int x = 0; x < 4; x++) {
				copy[y][x] = cmp[x][3 - y];
			}
		}

		for (int i = 0; i < 4; i++) { // ��ġ �̵� for ��
			for (int y = 0; y < 4; y++) {
				ny = y + dy[i];
				for (int x = 0; x < 4; x++) {

					nx = x + dx[i];

					store[cnt][ny][nx].num += copy[y][x].num;

					if (store[cnt][ny][nx].num > 9) store[cnt][ny][nx].num = 9;
					else if (store[cnt][ny][nx].num < 0) store[cnt][ny][nx].num = 0;

					if (copy[y][x].color != 'W') store[cnt][ny][nx].color = copy[y][x].color;

				}
			}

			func(cnt + 1);

			memcpy(store[cnt], store[cnt - 1], sizeof(store[cnt]));
		}
		memcpy(cmp, copy, sizeof(copy));

	}

}


void func(int cnt) {

	if (cnt == 4) {
		int r = 0; 
		int b = 0; 
		int g = 0; 
		int ye = 0;

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				char temp = store[cnt - 1][y][x].color;
				int temp_num = store[cnt - 1][y][x].num;

				if (store[cnt - 1][y][x].color == 'R') r += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'B') b += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'G') g += store[cnt - 1][y][x].num;
				else if (store[cnt - 1][y][x].color == 'Y') ye += store[cnt - 1][y][x].num;
			}

		}

		MAX = max(MAX, 7 * r + 5 * b + 3 * g + 2 * ye);
		return;
	}

	for (int i = 0; i < n; i++) {

		if (!visited[i]) {
			visited[i] = true;
			position(cnt, i);
			visited[i] = false;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 5x5 ���� ���� �ٸ� ��� 3�� 
	// ��� �ĺ��� 10�� ����
	// �� ĭ���� ǰ���� ��Ÿ���� ���ڿ� ���Ҹ� ��Ÿ���� ���� ĥ���� �ִ�.
	// �ʱ⿡�� ��� ĭ�� ǰ���� 0, ���Ҵ� ����̴�. ���� 4x4 ������� ��������,
	// ����� i�� j������ 2���� ������ �ִ�.
	// ȿ��: ���� �� ĭ�� ǰ���� �ٲٴ� -9�̻� 9������ ����
	// ���� : ���� ��ĭ�� ���Ҹ� �ٲ� �� �ִ� ��(R,B,Y,W)
	// ��ᰡ ��ġ�� ������ ����ĭ�� �ִ� ǰ���� ���Ұ����� �ٲ� �� �ִ�.
	// ������ ǰ���� ����� ȿ���� ��������. ���� ���� ���� ������ ��� 0���� 9�ʰ��� ��� 9�� �ٲ��.\
	// ������ ���� ����� ���Ұ� ����� ��� �״��, �ƴ� ��� ����� ���ҿ� ���� ������ ĥ������. 

	// ��� 3���� ��� �־�߸� ��ź�� ���������, ��ź�� ǰ���� ������ ���� ����Ѵ�. 
	// ��ź�� ǰ�� 7R + 5B + 3G + 2Y 

	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> arr[i][y][x].num;
			}
		}

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> arr[i][y][x].color;
			}
		}

	}

	func(1);
	cout << MAX;

}
