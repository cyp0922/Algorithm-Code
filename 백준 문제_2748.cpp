#include<iostream>
#include<algorithm>

using namespace std;

int arr[91];
int num; 
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> num;
	
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i=2; i<=num; i++){
		arr[i] = arr[i-1] + arr[i-2];
	} 
	
	cout << arr[num];
} 
