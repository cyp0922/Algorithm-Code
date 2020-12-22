#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num;
	string input;
	
	cin >> input;
	cin >> num;
	
	list<char> arr(input.begin(),input.end()); // list 생성 string의 마지막은 NULL; 
	auto cursor =  arr.end(); // 현재 커서는 마지막 NULL 가리킨다 
	
	char C;
	
	for(int x =0; x < num; x++){

		cin >> C;
		if(C == 'L'){
			if(cursor != arr.begin()) cursor--;
 		}
		else if(C == 'D'){
			if(cursor != arr.end()) cursor ++;
		}
		else if(C == 'B'){
			if(cursor !=arr.begin()){
				cursor = arr.erase(--cursor);
			}
		}
		else if(C == 'P'){
			char A;
			cin >> A;
			arr.insert(cursor,A);
		}
	}
	
	for(auto a = arr.begin(); a !=arr.end(); a++){
		cout << *a;
	}	

}


