#include<iostream>
#include<cmath>
using namespace std;

int num;

int arr[9];
int cmp[9]; //���� �迭 
bool visited[9];
int MAX = 0;

void dfs(int cur,int cnt ){
	
	if( cnt == num ){  // ���� �迭�� �� n���� �ɰ�� 
		
		int sum=0; 
		
		for(int i=0; i<num-1; i++){
			sum += abs(cmp[i] - cmp[i+1]);
		}
		
		MAX = sum > MAX ? sum : MAX;  // �ִ밪  
	}
	else{		// �ȵɰ�� ��� ä������ 
		
		for(int i= 0; i<num; i++){
		
			
			if(!visited[i]){			
				visited[i] = true;
				cmp[i] = arr[cur];
				dfs(cur+1,cnt+1);	 // vistied �迭�� ����Ͽ� ��� ����� �� Ž�� 
				visited[i] = false;
			}
		} 
	}
		
}
	

int main(){
	
	scanf("%d",&num);
	
	for(int i=0; i<num; i++) scanf("%d",&arr[i]);

	dfs(0,0);
	
	cout << MAX;
}
