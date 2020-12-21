#include<iostream>
#include<cmath>

using namespace std; 

int arr[31] = {0,};

int main() {
	
	int num ;
	float sum = 0;
	int cmp;
	
	scanf("%d",&num);
	
	if(num ==0){
		printf("0");
		return 0;
	}
	
	int cut = round(num*0.15);
	int l_cut = cut;
	int r_cut = cut;
	
	
	for(int i=0; i<num; i++){
		scanf("%d",&cmp);
		arr[cmp]++;
	}
	
	int l_cnt = 1;
	int r_cnt = 30;
	
	while( l_cut>0 ){ // 작은 값제거 
		if(arr[l_cnt] && l_cut){
			arr[l_cnt]--;
			l_cut--;
		}
		else l_cnt++; 
	}
	while( r_cut>0 ){ // 큰값 제거 
		if(arr[r_cnt] && r_cut){
			arr[r_cnt]--;
			r_cut--;
		}
		else r_cnt--;
	}
	
	l_cnt=0; // 횟수 
	r_cnt=1; // 숫자 1~30
	
	while(l_cnt<num-2*cut){
	
		if(arr[r_cnt]){
		
			sum += r_cnt;
			arr[r_cnt]--;
			l_cnt++;
		}
		else r_cnt++;
	}

	sum = round(sum/(num-2*cut));
	printf("%d",(int)sum);
	
	
}
