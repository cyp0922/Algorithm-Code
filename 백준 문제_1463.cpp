#include<iostream>
#include<algorithm>

using namespace std;

int arr[10000001];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num;
	
	cin >> num;
	
	arr[1] = 0;
	
	for(int i=2; i<=num; i++){
		
		arr[i] = arr[i-1]+1;
		
		if(i%3 ==0){
			arr[i] = min(arr[i/3]+1,arr[i]);
		}
		if(i%2 ==0){
			arr[i] = min(arr[i/2]+1,arr[i]);
		}
		
	}
	
	cout << arr[num];
	
	
}
