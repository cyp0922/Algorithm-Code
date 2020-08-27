#include<stdio.h>
#include<algorithm>

using namespace std; 

int stair[301];
int store[301][2];
int num;


int main(){
	int input;
	
	scanf("%d",&num);
	for(int i=1; i<=num; i++){
		scanf("%d",&input);
		stair[i] = input;
	}
	
	if(num <0) return 0;
	else store[1][1] = store[1][0] = stair[1];

	for(int i = 2; i <= num; i++){
		
		store[i][0] = max( store[i-2][0] , store[i-2][1] ) + stair[i];
		store[i][1] = store[i-1][0] + stair[i]; 
	}

	printf("%d",max(store[num][0] , store[num][1]));
	//printf("%d",store[1][0]);
}
