#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int map[1000][1000] = {0, };
int visited[1000][1000][2] = {0, };
	

struct m{
	int x;
	int y;
	int cnt;
};

int bfs(){
	
	queue<m> q;
	q.push({0,0,1});
	visited[0][0][1] = true;
	
	while(!q.empty()){
		
		int x = q.front().x;
		int y = q.front().y;
		int block = q.front().cnt;
		q.pop();
		
		if(x == N-1 && y == M-1) return visited[x][y][block];
		
		for(int i=0; i<4; i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if(new_x >=0 && new_x <N && new_y >=0 && new_y <M ){
				
				if(map[new_x][new_y] == 1 && block){
					visited[new_x][new_y][block -1] = visited[x][y][block] + 1;
					q.push({new_x,new_y,block-1}); 
				}
				
				if( map[new_x][new_y] == 0 && visited[new_x][new_y][block] ==0 ){
					visited[new_x][new_y][block] = visited[x][y][block] +1;
					q.push({new_x,new_y,block}); 
				}
			
			}
		}
		
	}
	
	return -1;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M; 
	
	for(int k=0; k<N; k++){
		for(int g=0; g<M; g++){
			
			scanf("%1d",&map[k][g] );
		}
	}
	
	cout << bfs() <<endl; 
	
	for(int k=0; k<N; k++){
		for(int g=0; g<M; g++){
			
			cout << visited[k][g][0] << " ";
		}
		cout <<endl;
	}
	
}
