#include<iostream>

using namespace std;

int main(){
	
	int L,P,V;
	int cnt =1;
	int ans;
	
	while(true){
		
		ans = 0;
		cin >> L>>P>>V;
		
		if(L==0 && P==0 && V==0){
			break;
		}
		
		while(V>0){
			
			if( V-P >0 ){
				V = V-P;
				ans += L;
			}
			else{
				if( V > L ) ans += L;
				else ans += V; 
				break;
			}
		} 
		
		cout << "Case " << cnt << ": " << ans << endl;
		cnt ++;
	
	}
}
