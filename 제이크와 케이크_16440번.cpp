#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N; // 과일 조각 4의 배수
bool arr[2000001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// s딸기, k 키위
	char c;

	cin >> N; 

	for (int i = 1; i <=N; i++) {
		cin >> c;
		if (c == 's') arr[i] = 1; // 딸기는 1
		else arr[i] = 0; // 키위는 0
	}

	//각자 n/4 딸기 n/4 키위를 가지고 있어야한다.
	// s딸기(1), k 키위(0)

	int window = N / 2;
	int s = 0;
	int k = 0;
	vector<int> v;

	for (int j = 1; j <= window; j++) {
		if (arr[j]) s++;
		else k++;
	}

	for (int i = 1; i <= N / 2 + 1; i++) {
		
		if (s == N / 4 && k == N / 4) {
			if (i != 1) v.push_back(i - 1);
			if (i != N / 2 + 1) v.push_back(i + window - 1);
			break;
		}

		if (arr[i]) s--;  // 슬라이딩 앞부분
		else k--;

		if (arr[window + i]) s++; // 슬라이딩 뒷부분
		else k++;
		

	}
	
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

}