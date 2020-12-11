#include<iostream>
#include<string.h>
using namespace std;

int num;

char star[2][3072][6143];
bool flag = true;

void tree(int cnt){
	
	if(cnt == num) return;
	
	flag = !flag; //1->0  0->1              // flag�� ���� star[0] star[1] �� ������ �����ư��鼭 ���  
	
	for(int i=0; i<cnt; i++ ){
		for(int j=0; j<2*cnt-1; j++){
			if(star[flag][i][j] == '*'){
				star[!flag][i][j+cnt] = '*'; //���� ��� �ﰢ�� 
				star[!flag][i+cnt][j] = '*'; //�����ϴ� 
				star[!flag][i+cnt][j+2*cnt] = '*'; // ������ �ϴ� 
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
	
	// �� ���� 
	star[0][0][2] = star[0][1][1] = star[0][1][3] = star[0][2][0] = star[0][2][1] = star[0][2][2] = star[0][2][3] = star[0][2][4] ='*';
	
	int cmp = 3;
	for(int i=0; i<=10; i++){
		if(num==cmp){
			tree(3);
			for(int k=0; k<num; k++){
				for(int n=0; n<2*num-1; n++){
					printf("%c",star[!flag][k][n]);
				}
				if(k != num-1)printf("\n");  // �������� ���� 
			}
			return 0;
		}
		
		cmp *=2; 
	}	
	
}
