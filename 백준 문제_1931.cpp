#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct m{
	int s;
	int e;
};



bool cmp( m a, m b ){
	if(a.e == b.e)	return a.s < b.s;
	
	return a.e < b.e;
}

int main(){
	
	int num; 
	cin >> num; 
	
	vector<m> meet(num);
	
	for(int i=0; i< num; i++){
		cin >> meet[i].s >> meet[i].e; 
	}
	
	sort(meet.begin(), meet.end(),cmp);
	
	int end = meet[0].e;
	int cnt =1;
	
	for(int i=1; i<num; i++){
		if(end <= meet[i].s){
			cnt ++;
			end = meet[i].e;
		}
	}
	cout << cnt;
}
