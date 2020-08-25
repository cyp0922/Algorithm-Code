#include<stdio.h>
#include<utility>
#include<vector>
using namespace std;

pair<int,pair<int,int> > cnt[41];

int fibo(int x){
	if(x ==0 ){
		return 0;
	}
	if(x==1){
		return 1;
	}
	if(cnt[x].first != 0){
		return cnt[x].first;
	}
	else{
		cnt[x].first = fibo(x-1) + fibo(x-2);
		cnt[x].second.first = cnt[x-1].second.first + cnt[x-2].second.first;
		cnt[x].second.second = cnt[x-1].second.second+ cnt[x-2].second.second;
		return cnt[x].first;
	}
}

int main(){
	int num,input;
	
	cnt[0].second = make_pair(1,0);
	cnt[1].second = make_pair(0,1);
	
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		scanf("%d",&input);
		if(!(input<=40) || input<0) return 0;
		fibo(input);
		printf("%d %d\n",cnt[input].second.first,cnt[input].second.second);
	}
	
}
