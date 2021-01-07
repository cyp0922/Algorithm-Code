#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	int A, P;
	
	vector<int> arr;
	
	cin >> A >> P;
	
	int cnt = 0;
	string temp;

	arr.push_back(A);

	while (true) {
		
		temp = to_string(arr[cnt]);
		int sum = 0;

		for (int i = 0; i < temp.length(); i++) {
			sum += pow(temp[i] - '0', P);
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == sum) {
				cout << i;
				exit(0);
			}
		}

		arr.push_back(sum);
		cnt++;

	}


}