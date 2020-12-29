#include<iostream>

using namespace std;

int arr[21];
int visited[21];

int N,S;
int cnt = 0;

// x == N 인 경우 마지막 부분 포함을 안하니 조심
// sum이 초기값이 0이므로 처음에 x = 0일시 cnt가 추가될수도있음 조심  

void back(int x,int sum){
	
	if(x==N+1) return;
	
	if(sum == S && x !=0) cnt ++; 
	
	for(int i=x+1; i<=N; i++){
		if(!visited[i]){
			visited[i] = true;
			back(i,sum + arr[i]);
			visited[i] = false;
		}
	}
		
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S; 
	
	for(int i=1; i<=N; i++) cin >> arr[i];
	
	back(0,0);
	
	cout << cnt; 
	

}

