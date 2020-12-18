#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[21][21];
int visited[21];
int diff = 987654321;
int N; 

void dfs(int cur,int cnt){
	
	if(cnt == N/2){
		
		vector<int> start,link;
		for(int i=1; i<=N; i++){
			if(visited[i]) start.push_back(i);
			else link.push_back(i); 
		}
		int start_cnt =0, link_cnt =0; 
		
		for(int i=0; i<N/2; i++){
			for(int j=i+1; j<N/2; j++)
			{
				int start_x = start[i]; int start_y=start[j];
				int link_x = link[i]; int link_y= link[j];
				start_cnt += arr[start_x][start_y] + arr[start_y][start_x];
				link_cnt += arr[link_x][link_y] + arr[link_y][link_x];
			}
		}
		diff = min(diff,abs(link_cnt-start_cnt));
		return;
	
	}
	
	for(int i = cur+1; i<=N; i++){
		visited[i] = true;
		dfs(i,cnt+1);
		visited[i] = false;
	}
	
}

int main(){

	scanf("%d",&N);
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	dfs(0,0);
	cout << diff;
}
