#include<iostream>

using namespace std;


int N,K,M;

int dfs(int cnt){
	
	
	if(K==M) return cnt; 
	
	else{
		K = K/2 + K%2;
	 	M = M/2 + M%2;
	 	N = N/2 + N%2;
	 	
	 	return dfs(cnt+1);
	 	
	}
	
}

int main(){
	
	scanf("%d %d %d",&N,&K,&M);
	
	cout << dfs(0);
	
}
