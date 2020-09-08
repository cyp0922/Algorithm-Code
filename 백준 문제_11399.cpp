#include<iostream>
#include<algorithm>

using namespace std;

int p[1001];

int main(){
	int num; 
	cin >> num;
	
	for(int i=0; i<num; i++){
		cin >> p[i];
	}
	
	sort(p,p+num);
	
	int sum = p[0];
	
	for(int i=1; i<num; i++){
		p[i] = p[i] + p[i-1];
		sum += p[i];
	}
	
	cout << sum;
	
}
