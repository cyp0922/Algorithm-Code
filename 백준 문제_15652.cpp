#include<iostream>

using namespace std;

int N,M;
int arr[9];
int visited[9]; 

void back(int x){
	
	if(x == M){
		for(int i=1; i<= M; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i= arr[x]; i<= N; i++){
			arr[x+1] = i; 
			back(x+1);

	}
	
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	cin >> N >> M;
	
	arr[0] =1;
	back(0);
	

}

