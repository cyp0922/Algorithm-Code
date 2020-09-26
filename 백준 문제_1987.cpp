#include<iostream> 

using namespace std;

int R,C;

char map[20][20];
int alpha[26];
int big =0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

void dfs(int a, int b, int cnt){
	
	big = max(big,cnt);
		
	for(int i=0; i<4; i++){
		int x = a + dx[i]; 
		int y = b + dy[i];
		if( x>=0 && x<R && y>=0 && y <C ){
			
			int k = map[x][y] - 65;
			
			if(alpha[k]) continue;
			
			alpha[k]++; 
							
			dfs(x,y,cnt+1);
			alpha[k]--;			
		}
		
	} 
}

int main(){
	
	string input;
	
	cin >> R >> C;
	for(int i=0; i<R; i++){
		cin >> input;
		for(int j=0; j<C; j++){
			map[i][j] = input[j];
		}
	}
	
	alpha[map[0][0] -65]++;
	dfs(0,0,1);
	
	cout << big;
	
}
