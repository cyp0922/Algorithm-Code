#include<iostream>
#include<string>

#define MAX 200002

using namespace std;


int arr[MAX];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	int num;
	string input;
	
	int front = MAX/2+1;
	int rear = MAX/2;
	
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> input;
		
		if(input == "push_front"){
			int num;
			cin >> num;
			front--;
			arr[front] = num;
			
		}
		else if(input == "push_back"){
			int num;
			cin >> num;
			rear++;
			arr[rear] = num;
		}
		else if(input == "pop_front"){
			if(front == rear+1) cout << "-1" << "\n";
			else{
				cout << arr[front] << "\n";
				front++;
			}
		}
		else if(input == "pop_back"){
			if(rear == front -1) cout << "-1" << "\n";
			else{
				cout << arr[rear] << "\n";
				rear--;
			}
		}
		else if(input == "front"){
			if(front == rear+1) cout << "-1" << "\n";
			else{
				cout << arr[front] << "\n";
			}
		}
		else if(input == "back"){
			if(rear == front -1) cout << "-1" << "\n";
			else{
				cout << arr[rear] << "\n";
			}
		}
		else if(input == "empty"){
			if(rear-front + 1==0) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if(input == "size"){
			cout << rear-front +1 << "\n";
		}
		
	}
	
	
}
