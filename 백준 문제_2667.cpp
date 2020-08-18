#include<iostream>
#include<utility>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int N;
int num = 1;
int visited[25][25];
int cnt[12]; 
string arr[25];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int a,int b){

      queue<pair<int,int> > q;
      q.push(make_pair(a,b));
      visited[a][b] = num;
      cnt[num] = 1;
      
      while(!q.empty()){
         
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         
         for(int i =0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >=0 && new_y >=0 && new_x < N && new_y <N && visited[new_x][new_y] ==0 && arr[new_x][new_y] == '1'){
               visited[new_x][new_y] = num;
               cnt[num]++;
               q.push(make_pair(new_x,new_y));               
            }
         }
      }
      
      num ++;
}

int main(){
   
   cin >> N;
   for(int i=0; i<N; i++){ 
      cin >> arr[i];
   }
   
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(!visited[i][j] && arr[i][j] =='1') {
            bfs(i,j);
         }
      }
   }
   
   sort(cnt,cnt+num);
   
   printf("%d\n",num-1);
   for(int i=1; i<=num-1; i++){
      printf("%d\n",cnt[i]);
   }

}

