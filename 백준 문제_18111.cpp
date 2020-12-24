#include<iostream>
#include<algorithm>
using namespace std;

int N,M,B;
int arr[501][501];
int min_time = 0x7f7f7f7f;
int top;

int main(){
	
	scanf("%d %d %d",&N,&M,&B);
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			scanf("%d",&arr[y][x]);
		}
	}

	for(int i=0; i<=256; i++){
		int temp;
		int time = 0;
		int block = B;
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				temp = i - arr[y][x];
				if(temp>0){ // 쌓아야할때 
					time += temp;
					block = block - temp; 
				}
				if(temp<0){ // 파야할때 
					time -= 2*temp;
					block = block + abs(temp);
				}
			}
		}
		
		if( block>=0 && min_time >= time){
			min_time= time;
			top = i;
		}
	}
	
	cout << min_time << " " << top;
} 
