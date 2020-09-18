#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	
	int num; 
	cin >> num;
	
	vector <int> a(num);
	
	for(int i=0; i<num; i++){
		cin >> a[i];
	}
	
	sort(a.begin(),a.end());
	
	int sum= 0;
	
	for(int i=0; i<num; i++){
		if(a[i] <=0 ) {
			if(a[i+1] <=0 && i+1 <num)
			{
				sum += a[i]*a[i+1];
				i++;
				continue;
			}
			else{
				sum += a[i];
				continue;
			}
		}
		if( a[i] != 1 && (num-i-1) % 2 == 1  && i+1 <num ){
			sum += a[i]*a[i+1];
			i++;
		}
		else{
			sum += a[i];
		}
		
	}
	
	cout << sum;
}
