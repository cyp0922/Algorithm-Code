#include<iostream>
#include<queue>
#include<vector>
 
using namespace std;
 
int N,K;
int visited[100001];
int position[2][3] = {{1,1,2},{1 ,-1,0}};

void bfs(int a,int b){ 

	queue<int> q;
	q.push(a);
	visited[a] = true;
	
	while(!q.empty()){ 
	
		int x = q.front();
		q.pop();
					
		for(int i=0; i<3; i++){
				int y= position[0][i]*x + position[1][i];
				
				if(y == b && y>=0){
					visited[y] = visited[x]+1;	
					return;				
				}	
				else if(!visited[y] && y>=0 && y<= 100000)
				{
					visited[y] = visited[x]+1;				
					q.push(y);
				}	
		}
	}
}	
	
int main(){
	cin >> N >> K;
	
	if(	 N!=K && N>=0 && K>=0 ){
		bfs(N,K);
		printf("%d",visited[K]-1);
	}	
	else if(N ==K) 
	{
		printf("0");
	}
}
	


