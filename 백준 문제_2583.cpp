#include<iostream>
#include<algorithm>

using namespace std;

int N,M,num;

int map[100][100] = {0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int a,int b, int cnt){
	map[a][b] = cnt;
	
	for(int i=0; i<4; i++){
		int x = a + dx[i];
		int y = b + dy[i];
		
		if(x>=0 && x<N && y >=0 && y<M && map[x][y] == 0 ){
			num++;
			dfs(x,y,cnt);
		}
	}
}

int main(){
	int K;
\
	
	cin >> N >> M >> K; 
	
	int number[N*M];
	
	int l_x,l_y,r_x,r_y;
	
	// 상자 입력 
	for(int i=0; i<K; i++){
		cin >> l_x >> l_y >> r_x >> r_y;
		for(int i = l_y; i < r_y; i++){
			for(int j = l_x; j<r_x; j++ ){
				map[i][j] = -1;
			}
		}
	}
	// dfs cnt 입력 
	int cnt = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				num=1;
				dfs(i,j,cnt) ;
				number[cnt] = num;
				cnt ++;
				
			} 
		}
	}

	sort(number+1,number+cnt);
	cout << cnt -1 <<endl; 
	for(int i=1; i<cnt; i++){
		cout << number[i] << " ";
	}
		
}
