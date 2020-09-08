#include<iostream>
#include<string>

using namespace std;

int a[25];

int main(){
	
	string input;
	
	cin >> input;
	
	int temp=0, sum =0, cnt =0;
	
	
	for(int i=0; i<input.length(); i++){
		if(input[i] == '-'){
			sum += temp;
			a[cnt] = sum;
			sum = 0;
			temp = 0;
			cnt ++;
		}
		else if( input[i] == '+'){
			sum += temp;
			temp = 0;	
		}
		
		else{
			temp *= 10;
			temp += (input[i] - '0');
		}
	}
	
	sum += temp;
	a[cnt] = sum;
	
	int result = a[0];
	
	for(int i=1; i<=cnt; i++){
		result -= a[i];
	}
	
	cout << result;
	
}
