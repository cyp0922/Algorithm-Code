#include<iostream>

using namespace std;

int row,col;
char map[1001][52];
char start[26];
char result[26];
char temp[26];
string input;
string answer;

void up(char R,int y, int x){   // 결과 값부터 ? 까지 올라가는 함수 
   
   for(int a=-1; a<=1; a+=2){
      if(x+a>=0 && x+a <2*row){
         if(map[y][x+a] == '-'){
            map[y][x]=' ';
            map[y-1][x+2*a] = R;
            up(R,y-1,x+2*a);
            return;
         }
         else if(map[y][x+a] == '?') { // ? 일때 temp배열에 나온 값들을 저장 
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

void down(char R,int y, int x){  // 처음입력값 부터 ? 까지 사다리를 타고 내려가는 함수 

   
   for(int a=-1; a<=1; a+=2){
      if(x+a>=0 && x+a <2*row){
         if(map[y][x+a] == '-'){
            map[y][x]=' ';
            map[y+1][x+2*a] = R;
            down(R,y+1,x+2*a);
            return;
         }
         else if(map[y][x+a] == '?') {  // ? 일때 start배열에 나온 값들을 저장 
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
   
   cin >> input; 	//결과값 입력 
   for(int i=0; i<row; i++ ){
      result[i] = input[i];
   }
   
   for(int y =0; y<col; y++){  //map 입력 
      cin >> input;
      for(int x =0; x<row; x++){
         map[y][2*x+1] = input[x];
      }
   }
   
   for(int k=0; k<row; k++) down( 'A'+k,0,2*k);    // A부터 row-1 갯수의 알파벳 입력 
    
   for(int k=0; k<row; k++) up(result[k],col,2*k);  // 입력받은 결과값을 재귀함수에입력 
   
   for(int k=0; k<row-1; k++){
      if(start[k]==temp[k]){   // 배열이같으면 * 
         answer+= '*';
      }
      else{
         if(start[k]==temp[k+1]){	// 우측으로 밀려져있으면 -  
            answer+= '-';
         }
         else if(start[k] == temp[k-1]){	// 좌측으로 밀려져있으면 * 
            answer += '*';   
         }
         else{		// 방법이 없으므로 string을 초기화한후 row-1만큼 x 입력 
            answer.clear(); 
            for(int i=0; i<row-1; i++) answer+='x';
            cout << answer;
            return 0;
         }
      }
   }

   cout << answer;
      
}
