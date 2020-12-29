#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int test;
int arr[101];
int store[101][101]; 

int main(){
	
	scanf("%d",&test);
	
	for(int p=0; p<test; p++){
		
		int num,vote;
		int MAX = 0;
		
		scanf("%d %d",&num,&vote);
		
		for(int i=0; i<vote; i++){
			
			for(int j=0; j<num; j++){
				scanf("%d",&store[i][j]);
				if(j==0) arr[store[i][j]]++;
			}
		}
		
		int first=0,second=0;
		
		for(int i=1; i<=num; i++){
			if(arr[first] < arr[i] ) first = i;
		}
		for(int i=1; i<=num; i++){
			if(arr[second] < arr[i] && i != first) second = i;
		}
		
		if(arr[first] > vote/2 ) cout << first << " 1" <<endl;
		else {
			for(int i=0; i<vote; i++){
				for(int j=0; j<num; j++){
					if(store[i][0] == first || store[i][0] == second) break;
					
					if(store[i][j] == first || store[i][j] == second){
						arr[store[i][j]]++;
						break;
					}
				}
			}
			int MAX = arr[first] > arr[second] ? first : second ;
						
			cout << MAX << " 2" <<endl;
		}
		memset(arr,0,sizeof(arr));
		for(int i=0; i<vote; i++){
			memset(store[i],0,sizeof(store[i]));
		}
		
	}
	
	
} 
