#include<iostream>
#include<algorithm>

using namespace std;

bool compare(string a, string b){
	
	if(a.length() < b.length()){
		return 1;
	}
	else if(a.length() > b.length()){
		return 0;
	}
	else{
			return a<b;

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
	
	for(int i=0; i<num; i++){
		if(array[i] == array[i+1]){
			continue;
		}
		
		cout << array[i] << endl;
		
	}
	
}
