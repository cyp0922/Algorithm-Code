#include<stdio.h>

int a[1002];

int dp(int x){
	if( x==1 ) return 1;
	if( x==2 ) return 2;
	if(a[x] !=0){
		return a[x];
	}
	else{
		return a[x] = dp(x-1)% 10007 + dp(x-2)% 10007;
	}
}

int main(){
	int input,result; 
	scanf("%d",&input);
	printf("%d",dp(input)% 10007);
	
}
