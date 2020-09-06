#include<iostream>

using namespace std; 

int main(){

	int input;
	int cnt = 0; 
	
	int  a[6] = { 500, 100, 50, 10, 5, 1};
	
	cin >> input; 
	
	input = 1000 - input;
	
	for(int i =0; i< 6; i++){
		while( input - a[i] >=0 )
		{
			input = input - a[i];
			cnt ++; 
			
		}
	}
	cout << cnt; 

}
