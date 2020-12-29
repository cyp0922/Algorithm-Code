#include<iostream>

using namespace std;

int arr[10];
int visited[10];
int N,M; 

void back(int cnt){
	
	if(cnt == M){
		for(int i=1; i<=M; i++){
			cout << arr[i] << " "; 
		}
		cout << "\n";
		return;
	}
	
	for(int i=1; i<=N; i++){
		if(!visited[i]){
			visited[i] = true;
			arr[cnt+1] = i;
			back(cnt+1);	
			visited[i] = false;
		}
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	back(0);
	
}
