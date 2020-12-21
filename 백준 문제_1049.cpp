#include<iostream>

using namespace std;

int brand[50][2];

int main(){
	
	int num,item;
	
	scanf("%d %d",&num,&item);
	
	int min_set = 1000; 
	int min = 1000;
	int sum = 0;
	
	for(int i=0; i<item; i++){
		scanf("%d %d",&brand[i][0],&brand[i][1]);
		if(min_set > brand[i][0]) min_set = brand[i][0]; // 세트에서의 최솟값 
		if(min > brand[i][1]) min = brand[i][1];		// 낱개에서의 최솟값 
	}
	
	
	int set_cnt=0;
	int cnt =0;; 
	while(num>0){
		if(num-6 >0){
			set_cnt++;
			num = num - 6;
			continue;		
		}
		cnt++;
		num = num-1;
	}
	if( min_set > 6*min ) sum = (6*set_cnt+cnt)*min; // 세트가격보다 낱개가격이 저렴할경우 
	else if( min_set < cnt*min ) sum = (set_cnt+1)*min_set; // 남은 낱개갯수의 가격보다 세트가격이 더 저렴하면 세트 하나더 추가 
	else sum = set_cnt*min_set + cnt*min;
	
	printf("%d",sum);
	
} 
