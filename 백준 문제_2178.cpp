#include<iostream>
#include<utility>
#include<queue>
#include<string>

using namespace std;

int N,M;
int visited[100][100];
string arr[100];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int a, int b){
	visited[a][b] = true;
	queue< pair<int,int> > q;
	q.push(make_pair(a,b));
	
	while(!q.empty()){
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int new_x =  x + dx[i];
			int new_y =  y + dy[i];
			if(new_x >=0 && new_x < N && new_y >=0 && new_y < M && visited[new_x][new_y] == 0 && arr[new_x][new_y] == '1') {
				q.push(make_pair(new_x,new_y));
				visited[new_x][new_y] = visited[x][y] +1;
			}
		}
		
	}
}

int main(){
	
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	bfs(0,0);
	
	printf("%d",visited[N-1][M-1]);
		
}
