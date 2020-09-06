#include<iostream>

using namespace std;

int n_list[1001];

int main(){
	
	int N,K,input;
	int cnt = 0;
	cin >> N>>K;
	
	for(int i=0; i<N; i++){
		cin >> input;
		n_list[i] = input;
	}
	
	
	for(int i = N-1; i>=0; i--){
		while(K - n_list[i] >=0){
			K = K - n_list[i];
			cnt ++;
		}
	}	
	
	cout << cnt;
}
