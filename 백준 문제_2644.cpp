#include<iostream>
#include<vector>

using namespace std;

vector<int> family[100];
int visited[100];
int a,b;

void dfs(int x){
	if( x == b ) return; 
	
	for(int i=0; i<family[x].size(); i++){
		int y= family[x][i];
		if(!visited[y]){
			visited[y] = visited[x] + 1;
			dfs(y);
		}
	}
}

int main(){
	int num,m,x,y;
	scanf("%d",&num);
	scanf("%d %d",&a,&b);
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d %d",&x,&y);
		family[x].push_back(y);
		family[y].push_back(x);
	}
	
	visited[a] = true;
	dfs(a);
	
	if(visited[b] !=0 )cout << visited[b] -1;
	else cout << "-1";
}
