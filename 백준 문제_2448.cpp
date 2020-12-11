#include<iostream>
#include<string.h>
using namespace std;

int num;

char star[2][3072][6143];
bool flag = true;

void tree(int cnt){
	
	if(cnt == num) return;
	
	flag = !flag; //1->0  0->1              // flag를 통해 star[0] star[1] 의 공간을 번갈아가면서 사용  
	
	for(int i=0; i<cnt; i++ ){
		for(int j=0; j<2*cnt-1; j++){
			if(star[flag][i][j] == '*'){
				star[!flag][i][j+cnt] = '*'; //제일 상단 삼각형 
				star[!flag][i+cnt][j] = '*'; //왼쪽하단 
				star[!flag][i+cnt][j+2*cnt] = '*'; // 오른쪽 하단 
			}
		}
	}
	
	for(int n =0; n<cnt; n++) memset(star[flag][n],' ',sizeof(char)*(2*cnt-1));
	
	tree(2*cnt);
	
}


int main(){
	
	scanf("%d",&num);
	
	for(int m =0; m<2; m++){	
		for(int n =0; n<num; n++){
			memset(star[m][n],' ',sizeof(char)*(2*num-1));
		}
	}
	
	// 별 삽입 
	star[0][0][2] = star[0][1][1] = star[0][1][3] = star[0][2][0] = star[0][2][1] = star[0][2][2] = star[0][2][3] = star[0][2][4] ='*';
	
	int cmp = 3;
	for(int i=0; i<=10; i++){
		if(num==cmp){
			tree(3);
			for(int k=0; k<num; k++){
				for(int n=0; n<2*num-1; n++){
					printf("%c",star[!flag][k][n]);
				}
				if(k != num-1)printf("\n");  // 마지막줄 제거 
			}
			return 0;
		}
		
		cmp *=2; 
	}	
	
}
