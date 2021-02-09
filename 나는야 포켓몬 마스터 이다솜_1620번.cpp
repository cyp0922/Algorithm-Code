#include<iostream>
#include<map>
#include<string>
#include<cctype>
using namespace std;

map<string, string> me;
map<string, string> re_me;

int N, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 도감에 수록 N개, 맞춰야하는 문제의 개수 M 

	cin >> N >> M;

	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		me.insert({ input, to_string(i) });
		re_me.insert({ to_string(i),input });
	}

	for(int i=0; i<M; i++){
		cin >> input;
		if (isdigit(input[0])) {
			cout << re_me[input] << "\n";
		}
		else cout << me[input] << "\n";
	}

}