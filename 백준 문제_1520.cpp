#include<iostream>
#include<cstring>
using namespace std;

int N,M;
int arr[501][501] ;
int visited[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dfs(int y, int x){

	if(y == N-1 && x == M-1 ){
		return 1;
	}
	
	if(visited[y][x] != -1) return visited[y][x]; 
	visited[y][x] = 0;
	
	for(int i=0; i<4; i++){
		int n_x = x + dx[i];
		int n_y = y + dy[i];
		if( n_x >= 0 && n_x <M && n_y >=0 && n_y <N ){
			if(arr[y][x] > arr[n_y][n_x]){
				visited[y][x] += dfs(n_y,n_x);
			}
		}
	}
	
	return visited[y][x];
	
}

int main(){
	
	scanf("%d %d",&N,&M);
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			scanf("%d",&arr[y][x]);
		}
	}
	
	memset(visited,-1,sizeof(visited));
	
	cout << dfs(0,0);

}
