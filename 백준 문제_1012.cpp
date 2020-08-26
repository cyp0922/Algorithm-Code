#include<iostream>
#include<queue>

using namespace std;

bool map[50][50];
int visited[50][50];

int N,M;
int cnt = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int a,int b){
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if(new_x >=0 && new_x<M && new_y>=0 && new_y <N && !visited[new_x][new_y] && map[new_x][new_y] ){
				visited[new_x][new_y] = true;
				q.push(make_pair(new_x,new_y));
			}
		}
		
	}
	
	cnt ++;
}

int main(){
	int test,line,a,b;
	
	scanf("%d",&test);
	
	int store[test];
	
	for(int i =0; i< test; i++){
		scanf("%d %d %d",&M,&N,&line);
		
		for(int j=0; j<line; j++){
			scanf("%d %d",&a,&b);
			map[a][b] = true;
			
		}
		
		
		for(int k=0; k<M; k++){
			for(int l =0; l<N; l++){
				if(!visited[k][l] && map[k][l]){
					bfs(k,l);
				}	
			}
		}
		
		
		store[i] = cnt;
		
		cnt =0;
		
		for(int z=0; z<M; z++){
			for(int c =0; c<N; c++){
				map[z][c] = 0;
				visited[z][c] = 0;			
			}
		}
						
	}
	
	for(int i =0; i< test; i++){
		printf("%d\n",store[i]);
	}
}
