#include<stdio.h>
#include<algorithm>

using namespace std;

int store[125251];
int store_sum[125251];

int main(){
	
	int num, input;
	int cnt = 1;
	int big ;
	
	scanf("%d",&num);

	for(int i= 0; i<num*(num+1)/2; i++){
		scanf("%d",&input);
		store[i] = input;
	}
	
	store_sum[0] = store[0];
	big = store[0];

	for(int i=2; i<=num; i++){ //´Ü°è
		for(int j=0; j < i; j++){
			
			if( j!=0 && j!=i-1 ){
				store_sum[cnt] = max(store[cnt] + store_sum[cnt-i], store[cnt] + store_sum[cnt-i+1]);
			} 
			else if(j==0){
				store_sum[cnt] = store[cnt] + store_sum[cnt-i+1];
			}
			else if(j== i-1)
			{
				store_sum[cnt] = store[cnt] + store_sum[cnt-i];
			}
			
			big = max(big,store_sum[cnt]);
			cnt++;
				
		} 
		
	}
	int aa =0;
	for(int i= 0; i<=num; i++){
		for(int j =0; j<i; j++){
			printf("%d ",store_sum[aa]);
			aa++;
		}
		printf("\n");
	}
	
	printf("%d",big);
	
}
