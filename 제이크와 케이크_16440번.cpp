#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N; // ���� ���� 4�� ���
bool arr[2000001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// s����, k Ű��
	char c;

	cin >> N; 

	for (int i = 1; i <=N; i++) {
		cin >> c;
		if (c == 's') arr[i] = 1; // ����� 1
		else arr[i] = 0; // Ű���� 0
	}

	//���� n/4 ���� n/4 Ű���� ������ �־���Ѵ�.
	// s����(1), k Ű��(0)

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

		if (arr[i]) s--;  // �����̵� �պκ�
		else k--;

		if (arr[window + i]) s++; // �����̵� �޺κ�
		else k++;
		

	}
	
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

}