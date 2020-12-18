#include<iostream>

using namespace std;

int row,col;
char map[1001][52];
char start[26];
char result[26];
char temp[26];
string input;
string answer;

void up(char R,int y, int x){   // ��� ������ ? ���� �ö󰡴� �Լ� 
   
   for(int a=-1; a<=1; a+=2){
      if(x+a>=0 && x+a <2*row){
         if(map[y][x+a] == '-'){
            map[y][x]=' ';
            map[y-1][x+2*a] = R;
            up(R,y-1,x+2*a);
            return;
         }
         else if(map[y][x+a] == '?') { // ? �϶� temp�迭�� ���� ������ ���� 
            temp[x/2] = R; 
            return;
         }
      }
   }
   map[y][x]=' '; 
   map[y-1][x] = R;
   up(R,y-1,x);
   return;
}

void down(char R,int y, int x){  // ó���Է°� ���� ? ���� ��ٸ��� Ÿ�� �������� �Լ� 

   
   for(int a=-1; a<=1; a+=2){
      if(x+a>=0 && x+a <2*row){
         if(map[y][x+a] == '-'){
            map[y][x]=' ';
            map[y+1][x+2*a] = R;
            down(R,y+1,x+2*a);
            return;
         }
         else if(map[y][x+a] == '?') {  // ? �϶� start�迭�� ���� ������ ���� 
            start[x/2] = R;
            return;
         }
      }
   }
   
   map[y][x]=' ';
   map[y+1][x] = R;
   down(R,y+1,x);
   return;
 }

int main(){
   
   scanf("%d %d",&row,&col);    
   
   cin >> input; 	//����� �Է� 
   for(int i=0; i<row; i++ ){
      result[i] = input[i];
   }
   
   for(int y =0; y<col; y++){  //map �Է� 
      cin >> input;
      for(int x =0; x<row; x++){
         map[y][2*x+1] = input[x];
      }
   }
   
   for(int k=0; k<row; k++) down( 'A'+k,0,2*k);    // A���� row-1 ������ ���ĺ� �Է� 
    
   for(int k=0; k<row; k++) up(result[k],col,2*k);  // �Է¹��� ������� ����Լ����Է� 
   
   for(int k=0; k<row-1; k++){
      if(start[k]==temp[k]){   // �迭�̰����� * 
         answer+= '*';
      }
      else{
         if(start[k]==temp[k+1]){	// �������� �з��������� -  
            answer+= '-';
         }
         else if(start[k] == temp[k-1]){	// �������� �з��������� * 
            answer += '*';   
         }
         else{		// ����� �����Ƿ� string�� �ʱ�ȭ���� row-1��ŭ x �Է� 
            answer.clear(); 
            for(int i=0; i<row-1; i++) answer+='x';
            cout << answer;
            return 0;
         }
      }
   }

   cout << answer;
      
}
