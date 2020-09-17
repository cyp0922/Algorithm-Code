#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[100][100][100];
int visited[100][100][100];

int N,M,H;
int day =0;

struct m{
	int x;
	int y;
	int z;
};

queue<m> q;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};
void bfs(){
	
	
	while(!q.empty()){ 
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop(); 
		
		for(int i =0; i < 6; i++){
			int n_x = x + dx[i];
			int n_y = y + dy[i];
			int n_z = z + dz[i];
			if(n_x >=0 && n_x <M && n_y >=0 && n_y < N && n_z >=0 && n_z <H&& !visited[n_x][n_y][n_z] && !map[n_x][n_y][n_z]){
				visited[n_x][n_y][n_z] = visited[x][y][z] + 1;
				q.push({n_x,n_y,n_z});
				day = max(day,visited[n_x][n_y][n_z] -1 );
			}
		}
	}
}

int main(){
	
	cin >> N >> M  >> H;
	
	for(int k =0; k< H; k++){
		for(int i=0; i< M; i++){
			for(int j=0; j< N; j++){
				cin >> map[i][j][k];
				if(map[i][j][k] == 1){
					q.push({i,j,k});
					visited[i][j][k] = true;
				}
				if(map[i][j][k] == -1) visited[i][j][k] = -1;
			}
		}
	}
		
	bfs();
				
	int cnt = 0;
			
	for(int k =0; k<H; k++){			
		for(int i=0; i< M; i++){
			for(int j=0; j< N; j++){
				if( !visited[i][j][k] ) cnt ++;
			}
		}	
	}
			
	if(cnt != N*M && cnt!=0) {
		cout << -1 <<endl;
		return 0;
	}
			
	
		
	cout << day <<endl;
	
	
	for(int k =0; k<H; k++){
		for(int i=0; i< M; i++){
			for(int j=0; j< N; j++){
				cout << visited[i][j][k];
			}
			cout << endl;
		}	
		cout << endl;
	}
	 
	
}
