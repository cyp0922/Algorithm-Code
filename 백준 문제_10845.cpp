#include<iostream>
#include<string>

using namespace std;

int arr[100000];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int front = 0;
	int rear = 0;
	int num;
	string input;
	
	cin >> num; 
	
	for(int i=0; i<num; i++){
		cin >> input;
		if(input == "push"){
			int N;
			cin >> N;
			arr[rear] = N;
			rear++; 
		}
		else if(input == "pop"){
			if(front == rear) cout << "-1" << "\n";
			else{
				cout << arr[front]<< "\n";
				front++;
			}
		}
		else if(input == "front"){
			if(front == rear) cout << "-1"<< "\n";
			else cout << arr[front]<< "\n";
		}
		else if(input == "back"){
			if(front == rear) cout << "-1"<< "\n";
			else cout << arr[rear-1]<< "\n";
		}
		else if(input == "size") cout << (rear-1)- front +1<< "\n";
		else if(input == "empty"){
			if(front == rear) cout << "1"<< "\n";
			else cout << "0"<< "\n";
		}
	}	
	
}
