#include<iostream>

using namespace std;

int arr[21];
int visited[21];

int N,S;
int cnt = 0;

// x == N �� ��� ������ �κ� ������ ���ϴ� ����
// sum�� �ʱⰪ�� 0�̹Ƿ� ó���� x = 0�Ͻ� cnt�� �߰��ɼ������� ����  

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

