#include<iostream>
#include<vector>
#include<queue>

using namespace std; 

vector<int> com[101];
int visited[101];
int cnt =0;

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<com[x].size(); i++){
			int y = com[x][i];
			if(!visited[y]){
				visited[y] = true ;
				cnt ++;
				q.push(y);
			}
		}
		
	}
	
	
}

int main(){
	int num, line, a,b;
	scanf("%d %d",&num,&line);
	
	for(int i=0; i<line; i++){ 
		scanf("%d %d",&a,&b);
		com[a].push_back(b);
		com[b].push_back(a);
	}
	
	bfs(1);
	
	printf("%d",cnt); 
	
}
