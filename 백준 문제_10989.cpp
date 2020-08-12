#include<iostream>

using namespace std;

int main(){
	
	int num,input;
	
	scanf("%d",&num);
	
	int sort[10000] = {0,};
	
	
	for(int i=0; i<num; i++){
		scanf("%d",&input);
		sort[ (input-1) ] ++; 
	}
	
	for(int i=0; i<10000; i++){
		while(sort[i] != 0){
			printf("%d\n",i+1);
			sort[i]--;
		}
	}
}
