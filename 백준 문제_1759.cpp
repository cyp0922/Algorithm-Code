#include<iostream>
#include<algorithm>

using namespace std;

int L,C; 
char cmp[5] = {'a','e','i','o','u'};
char arr[16];
char temp[16];

void back(int x,int cnt){
	
	if(x == L && cnt >=1 && L - cnt >= 2){
		for(int i=1; i<=L; i++ ){
			cout << temp[i];
		}
		cout << "\n";		
 		return;
	}
	
	bool flag = false;

	for(int i= x + 1; i<= C; i++){
		
		flag = false;
		
		if( temp[x] < arr[i-1]){
			temp[x+1] = arr[i-1];
			
			for(int j=0; j<5; j++){				
				if(arr[i-1] == cmp[j]){
					flag = true;
					break;
				}
			}
			
			if(flag) back(x+1,cnt+1); 			
			else back(x+1,cnt);			
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> L >> C;
	
	for(int i=0; i< C; i++) cin >> arr[i];
	
	sort(arr,arr+C);
	
	temp[0] = 'a'-1;
	back(0,0);

}
