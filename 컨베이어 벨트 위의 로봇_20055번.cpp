#include<iostream>
#include<queue>
using namespace std;

int N, K;
int arr[201];
bool visited[101];
queue<int> q;


void move() {

	// �����̾� ��Ʈ ȸ��
	int temp = arr[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		arr[i] = arr[i - 1];
		if (i <= N) {
			visited[i] = visited[i - 1];
			visited[i - 1] = false;
		}
	}
	arr[1] = temp;
}

void robot_move() {

	if (visited[N]) visited[N] = false;
	for (int i = N - 1; i >= 1; i--) {
		if (visited[i]) {
			if (!visited[i + 1] && arr[i + 1]) {
				visited[i] = false;
				visited[i + 1] = true;
				arr[i + 1] --;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	
	//�κ��� � ĭ�� �ö󰡰ų� �̵��ϸ� �� ĭ�� �������� ��� 1��ŭ ����

	cin >> N >> K;
	int time = 1;

	int input; 
	for (int i = 1; i <= 2*N; i++) cin >> arr[i];


	while (true) {

		move();

		robot_move();

		// �κ� �߰�
		if (!visited[1] && arr[1]) {
			arr[1]--;
			visited[1] = true;
		}

		int cnt = 0;
		for (int i = 1; i <= 2 * N; i++) {
			if(!arr[i]) cnt++;
		}

		if (cnt >= K) {
			cout << time;
			exit(0);
		}
		time++;
	}
}