#include<iostream>
#include<queue>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int map[8][8];
int map_copy[8][8];
int visited[8][8];
int N,M;
int wall[1][3];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue< pair<int,int> > q;

void bfs(){
   
   while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      
      for(int i=0; i<4; i++){
         int new_x = x + dx[i];
         int new_y = y + dy[i];
         if(new_x>=0 && new_x <N && new_y >=0 && new_y <M && visited[new_x][new_y] !=-1 && map_copy[new_x][new_y] == 0 ) {
            q.push(make_pair(new_x,new_y));
            map_copy[new_x][new_y] = map_copy[x][y] +1;
         }
      }
   }
}

int main(){
   int input;
   int cnt = 0;
   
   scanf("%d %d",&N,&M);
   
	pair<int,int> two[N*M];
    int two_cnt = 0;
    int small =0;
   
   for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
         scanf("%d",&input);
         map[i][j] = input;
       	 map_copy[i][j] = input;
      }
   }
	
	//2 위치 확인
	 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 2){
				two[two_cnt].first = i;
				two[two_cnt].second = j;
				two_cnt++;
			}
		} 
	}
    
   // 1 입력 
   for(int x=0; x<N*M; x++){
   	
   		if(map_copy[x/M][x%M] == 0){	// x
   			map_copy[x/M][x%M] = 1;
   			
	   		for(int y=x+1; y<N*M; y++){
	   			
	   			if(map_copy[y/M][y%M] == 0){  // y 
	   				map_copy[y/M][y%M] = 1;
	   				
		   			for(int z=y+1; z<N*M; z++){
		   				
		   				if(map_copy[z/M][z%M] == 0){ // z
							map_copy[z/M][z%M] = 1;
							
							for(int i=0; i<two_cnt; i++){
								q.push(make_pair(two[i].first,two[i].second));
								visited[two[i].first][two[i].second] = -1;
							}
							
						    bfs();
						    // 0 갯수 
						    for(int i=0; i<N; i++){
						        for(int j=0; j<M; j++){
						       	  if(!map_copy[i][j]){
						             cnt++;
						          }
						        }
						  	}
						  	
						  	
						  	// 초기화 
						  	for(int k=0; k<N; k++){
						      for(int l=0; l<M; l++){
						         map_copy[k][l] = map[k][l];
								 visited[k][l] = 0; 				         
						      }
						   }
						   map_copy[x/M][x%M] = 1;
						   map_copy[y/M][y%M] = 1;
   						  	
						  	small = max(cnt,small);
							cnt = 0;						
					   }
					}
					map_copy[y/M][y%M] = 0;
				}				
			}
		 	map_copy[x/M][x%M] = 0;
		}		
   }
   
   printf("%d",small);
   
}
