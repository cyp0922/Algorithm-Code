#include<iostream>
#include<algorithm>

using namespace std;
long long dp[101];
long long arr[10];
long long temp[10];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num;
	cin >> num; 
	
	long long sum;
	dp[1] = 9;
	fill(arr,arr+10,1);
	arr[0] = 0;
	
	for(int k=2; k<=num; k++){
		
		sum =0;
		
		for(int i=0; i<=9; i++){
			
			if(i==0) temp[1] += arr[0]; 
			else if(i==9) temp[8] += arr[9];
			else{
				temp[i-1] += arr[i];
				temp[i+1] += arr[i];
			}
			
		}
		
		for(int j=0; j<=9; j++){
			arr[j] = temp[j] % 1000000000;
			sum += arr[j] ;
			temp[j] = 0;
		}
		
		dp[k] = sum % 1000000000;;
	}
	
	cout << dp[num];
	
}
