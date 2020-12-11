#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> input;

int main(){
	
	int in;
	int sum = 0;
	
	for(int i=0; i<9; i++ ){
		cin >> in; 
		input.push_back(in);
		sum += in;
	}
	
	sum = sum - 100;
	
	cout<< endl;
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(sum == input[i] + input[j]){
				input.erase(input.begin()+j);
				input.erase(input.begin()+i);
				
				sort(input.begin(),input.end());
				cout << endl;
				for(int i=0; i<7; i++ ){
					cout << input[i] << endl;
				}	
				return 0;
			}
		}
	}
	

	
	
}
