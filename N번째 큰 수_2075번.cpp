#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

priority_queue<int> q; 

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	int N;

	cin >> N; 
	int MAX = 0;
	int input;
	q.push(1e9);

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
		
			cin >> input; 

			if (input > -q.top()) {
				
				if (q.size() == N) {
					q.pop();
				}
				q.push(-input);
			}

		}
	}

	cout << -q.top(); 
	

}