#include<iostream>
#include<algorithm>

using namespace std;

int getSum(string a){
	
	int sum = 0;
	
	for(int i =0; i<a.length(); i++){
		if( a[i] - '0' >=0 && a[i] - '0' <= 9){
			sum += a[i] -'0';
		}
	}
	
	return sum;
}

bool compare(string a, string b){
	
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	else{
		int aSum = getSum(a);
		int bSum = getSum(b);
		
		if(aSum != bSum){
			return aSum < bSum;
		}
		else{
			return a < b;
		}
	}
	
}

int main(){
	
	int num;
	cin >> num;
	
	string array[num];

	for(int i=0; i<num; i++){
		cin >> array[i]; 
	}
	
	sort(array,array+num,compare);
	
	for(int i =0; i<num; i++){
		cout << array[i] << endl;
	}
}
