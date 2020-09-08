#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int num,input;
	int big =0;
	
	cin >> num;
	
	int a[num];
	
	for(int i=0; i<num; i++) {
		cin >> input; 
		a[i] = input;
		
	}
	sort(a,a+num);
	
	
	for(int i=0; i<num; i++){
		
		big = max(big, a[i]*(num-i));

	}
	
	cout << big;  

}
