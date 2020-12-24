#include<iostream>

using namespace std;
long long arr[16];
long long N,W;

int main(){
	
	scanf("%d %d",&N,&W);
	
	for(int i=1; i<=N; i++){
		scanf("%d",&arr[i]);
	}
	long long COIN; 
	
	for(int i=1; i<N; i++){
		if(arr[i] < arr[i+1]){
			COIN = W/arr[i];
			W = W % arr[i];
			W = W + COIN*arr[i+1];
			COIN = 0; 
		}
	}
	
	cout << W;
	
} 
