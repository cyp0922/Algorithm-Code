#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
int arr[51][51];
int cmp[51][51];

int cnt = 0;

int main(){
	
	cin >> N >> M;
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			scanf("%1d",&arr[y][x]);
		}
	}
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			scanf("%1d",&cmp[y][x]);
		}
	}
	
	for(int y=0; y<=N-3; y++){

		for(int x=0; x<=M-3; x++ ){
			if(arr[y][x] != cmp[y][x]){
				
				for(int a=y; a<y+3; a++){
					for(int b=x; b<x+3; b++){
						arr[a][b] = !arr[a][b];
					}
				}
							
				cnt++;
			}
		}
	}
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			if(arr[y][x] != cmp[y][x]){
				cout << "-1";
				exit(0);
			}
		}
	}
	
	cout << cnt;
	
}
