#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return b < a;
} 

int main(){
	int test;
	int C,B;
	
	scanf("%d",&test);
	
	for(int x=0; x<test; x++){
		vector <int> arr;
		scanf("%d %d",&C,&B);
		int a,b;
		for(int i=0; i<B; i++){
			scanf("%d %d",&a,&b);
			arr.push_back(a*b);
		}
		
		sort(arr.begin(),arr.end(),cmp); // �������� ���� 
		
		int sum=0;
		int cnt =0; 
		while(sum < C){ //������ ���� ������ �������� ���� ��� 
			sum += arr[cnt];
			cnt++;
		}
		
		cout << cnt << endl;
	}
	
}
