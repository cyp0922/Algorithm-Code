#include <iostream>
#include <queue>

using namespace std;

int map[300][300];
int map_copy[300][300];
int visited[300][300];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M;
int cnt;

struct s {
	int x;
	int y;
};


void dfs(int x, int y){
	
	if(cnt >=2) return;
	
	for(int i=0; i<4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if( new_x>=0 && new_x <N && new_y >=0 && new_y <M){
			
			if(map[new_x][new_y] == 0 && map_copy[x][y] >=1){
				map_copy[x][y] = map_copy[x][y] - 1;
			}
		}
		
    }
    
    for(int i=0; i<4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if( new_x>=0 && new_x <N && new_y >=0 && new_y <M && map[new_x][new_y] && !visited[new_x][new_y] ){
			visited[new_x][new_y] = true;	
			dfs(new_x,new_y);
		}
	}
}

int main(){
	
	int year = 0;
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){

			scanf("%d",&map[i][j]);
			map_copy[i][j] = map[i][j];
		}
	}
	
	while(true)
	{
		cnt =0;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				
				map[i][j] = map_copy[i][j];
				
				if(map[i][j] && !visited[i][j]){
					visited[i][j] = true;
					dfs(i,j);		
					cnt ++;			
				}
			}
		}	
		
		if(cnt >=2)  {		
			cout << year; 
			break;
		}
		if(cnt == 0) {
			cout << "0";
			break;
		}
		
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				visited[i][j] = 0;
			}
		}

		year++;
		
	}
	
	
}
