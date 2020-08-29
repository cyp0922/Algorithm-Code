#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int map[50][50];
int visited[50][50];
int count = 0;

int dx[8] = {-1,0,1,1,1,0,-1,-1 };
int dy[8] = {-1,-1,-1,0,1,1,1,0 };

int w,h;

void bfs(int a, int b){
	
	if(visited[a][b]) return;
	
	count ++;
	
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = count;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<8; i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if(new_x >=0 && new_x < h && new_y >=0 && new_y <w && map[new_x][new_y] == 1 && visited[new_x][new_y] == 0){ 
				q.push(make_pair(new_x,new_y));
				visited[new_x][new_y] = count ;
			}
		}
		
	} 
	
}

int main(){
	while(1)
	{
		
		scanf("%d %d",&w,&h);
		
		if(w==0 && h==0) break;
		
		for(int i=0; i<h; i++ ){
			for(int j=0; j<w; j++){
				scanf("%d",&map[i][j]);
			}
		}
		
		for(int i=0; i<h; i++ ){
			for(int j=0; j<w; j++){
				if(map[i][j] == 1){
					bfs(i,j);
				}
			}
		}

		printf("%d\n",count);
		count =0;
		
		for(int i=0; i<h; i++ ){
			for(int j=0; j<w; j++){
					map[i][j] = visited[i][j] = 0;
				}
			}
		}	
}
	
	
	

