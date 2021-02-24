#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N; 
vector<string> arr;
vector<pair<string,int>> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 파일을 확장자 별로 정리해서 몇개씩
	// 확장자들을 사전순으로 정렬
	string input;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> input;
		input.erase(0, input.find('.') + 1);
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int cnt = 0;
	v.push_back({ arr[0],1 });
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] != arr[i]) {
			v.push_back({ arr[i],1 });
			cnt++;
		}
		else v[cnt].second++;
	}

	for (auto i : v) {
		cout << i.first << " " << i.second << "\n";
	}

}