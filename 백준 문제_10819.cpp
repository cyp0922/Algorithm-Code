#include<iostream>
#include<cmath>
using namespace std;

int num;

int arr[9];
int cmp[9]; //저장 배열 
bool visited[9];
int MAX = 0;

void dfs(int cur,int cnt ){
	
	if( cnt == num ){  // 숫자 배열이 총 n개가 될경우 
		
		int sum=0; 
		
		for(int i=0; i<num-1; i++){
			sum += abs(cmp[i] - cmp[i+1]);
		}
		
		MAX = sum > MAX ? sum : MAX;  // 최대값  
	}
	else{		// 안될경우 계속 채워나감 
		
		for(int i= 0; i<num; i++){
		
			
			if(!visited[i]){			
				visited[i] = true;
				cmp[i] = arr[cur];
				dfs(cur+1,cnt+1);	 // vistied 배열을 사용하여 모든 경우의 수 탐색 
				visited[i] = false;
			}
		} 
	}
		
}
	

int main(){
	
	scanf("%d",&num);
	
	for(int i=0; i<num; i++) scanf("%d",&arr[i]);

	dfs(0,0);
	
	cout << MAX;
}
