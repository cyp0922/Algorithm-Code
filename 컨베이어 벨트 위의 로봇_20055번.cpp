#include<iostream>
#include<queue>
using namespace std;

int N, K;
int arr[201];
bool visited[101];
queue<int> q;


void move() {

	// 컨베이어 벨트 회전
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
	
	//로봇이 어떤 칸에 올라가거나 이동하면 그 칸의 내구도는 즉시 1만큼 감소

	cin >> N >> K;
	int time = 1;

	int input; 
	for (int i = 1; i <= 2*N; i++) cin >> arr[i];


	while (true) {

		move();

		robot_move();

		// 로봇 추가
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