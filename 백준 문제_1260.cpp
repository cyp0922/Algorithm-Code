#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> a[1001];
int c[10001];
int f[10001];


void dfs(int x){
   if(c[x])return;
   c[x] =true;
   printf("%d ",x);
   for(int i=0; i<a[x].size(); i++){
      int y = a[x][i];
      dfs(y);
   }
}


void bfs(int start){
   
   queue<int> q;
   q.push(start);
   f[start] = true;;
   
   while(!q.empty()){
      int x = q.front();
      q.pop();
      printf("%d ",x);
      
      for(int i=0; i<a[x].size(); i++){
         int y = a[x][i];
         if(!f[y]){
            q.push(y);
            f[y] = true; 
         }
      }
   }
   
}

int main(){
   
   int point,line,start,s,e;
   
   scanf("%d %d %d",&point,&line,&start);
   
   for(int i=0; i<line; i++){
      scanf("%d %d",&s,&e);
      a[s].push_back(e);
      a[e].push_back(s);
   }
   
   	for(int i=0; i<point; i++){
		sort(a[i].begin(),a[i].end());		
	}
   
   dfs(start);
   printf("\n");
   bfs(start);
   
   
}
