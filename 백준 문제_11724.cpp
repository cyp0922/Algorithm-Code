#include<iostream>
#include<queue> 
#include<vector>
using namespace std;

vector <int> point[1001];
int visited[1001];
int store[1001];
int count = 0;

void bfs(int x){
	
	if(visited[x]) return;
	
	queue<int> q;
	q.push(x);
	visited[x] = true;
	
	while(!q.empty()){
		
		int y = q.front();		
		q.pop();
		
		for(int i=0; i<point[y].size(); i++ ){
			int k = point[y][i];
			if(!visited[k]){
				q.push(k);
				visited[k] = true;
			}
		}
	}
	count ++;
}

int main(){
	int N,M,a,b;
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++){
		scanf("%d %d",&a,&b);
		
		point[a].push_back(b);
		point[b].push_back(a); 
		store[a] = true;
		store[b] = true;

	}
	
	for(int i=1; i<=N; i++){
		bfs(i);
	}
	
	printf("%d",count);
}
