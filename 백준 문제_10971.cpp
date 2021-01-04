#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[11][11];
int visited[11];
int ans = 987654321;

void back(int x,int d,int sum){
	
	if(x==N){
		for(int i=1; i<=N; i++){
			
			if(visited[i] == true && arr[d][i] ){
				ans = min(ans,sum + arr[d][i]);
				return;	
			}
		}
	}
	
	for( int i=1; i<=N; i++ ){
		if(!visited[i]){
			
			if(x!=0 && !arr[d][i]) return;
			
			if(x==0) visited[i] = true;
			else visited[i] = visited[d] + 1;
			
			back(x+1,i,sum+arr[d][i]);
			
			visited[i] = false;
			
		}
	}
	
}

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> arr[i][j];
		}
	}
	
	back(0,0,0);
	
	cout << ans;
	
}
