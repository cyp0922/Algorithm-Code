#include<stdio.h>
#include<algorithm>

int home[1001][3];
int store[1001][3];
int num;

using namespace std;

int main(){
	int r,g,b,temp;
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		scanf("%d %d %d",&r,&g,&b);
		home[i][0] = r;
		home[i][1] = g;
		home[i][2] = b;			
	}
	
	store[0][0] = home[0][0];
	store[0][1] = home[0][1];
	store[0][2] = home[0][2];
	
	for(int i=1; i<num; i++){
		
		temp = ( store[i-1][1] < store[i-1][2] ) ? 1:2;
		store[i][0] = home[i][0]+ store[i-1][temp];
		
		temp = ( store[i-1][0] < store[i-1][2] ) ? 0:2;
		store[i][1] = home[i][1]+ store[i-1][temp];
		
		temp = ( store[i-1][0] < store[i-1][1] ) ? 0:1;
		store[i][2] = home[i][2]+ store[i-1][temp];
	
	}
	
	printf("%d",min(min(store[num-1][0],store[num-1][1]),store[num-1][2]));
	
	
	
}
