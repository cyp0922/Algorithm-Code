#include<iostream>
#include<stack>

using namespace std;

int main(){
	
	stack<int> a;
	int num,input;
	int sum =0;
	
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> input;
		if(input == 0){
			a.pop();
		}
		else{
			a.push(input); 
		}
	}
	
	while(!a.empty()){
		sum += a.top();
		a.pop();
	}	
	
	cout << sum << endl;
}
