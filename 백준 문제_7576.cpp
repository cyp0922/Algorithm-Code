#include<iostream>
#include<queue>
#include<algorithm>

using namespace std; 

int box[1002][1002];
int visited[1002][1002];
int N,M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

struct map{
	int x;
	int y;
};

queue<map> q;

void bfs(){
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for(int i=0; i<4; i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if(new_x >= 0 && new_x < N && new_y >=0 && new_y <M && box[new_x][new_y] == 0 && visited[new_x][new_y] == 0){
				visited[new_x][new_y] = visited[x][y] + 1;
				q.push({new_x,new_y});	
			}
			
		}
		
		
	}
	
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> M >> N;
	
	for(int i=0; i< N; i++){
		for(int j=0; j<M; j++){
			cin >> box[i][j];
			if( box[i][j] == -1) visited[i][j] = -1;
			if( box[i][j] == 1 ){
				q.push({i,j});
				visited[i][j] = true; 
			}
		}
	}
	
	bfs();
	
	int big = 0;
		
	for(int i=0; i< N; i++){
		for(int j=0; j<M; j++){

			if(visited[i][j] ==0){
				cout << "-1" << endl;
				return 0;
			}
			big = max(big,visited[i][j]);
		}
	}
	
	cout << big-1;
}
