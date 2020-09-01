#include<iostream>
#include<vector>
#include<queue>

using namespace std; 

int N,M;

vector<pair<int,int> > a[1001];
int d[1001];

int INF = 987654321;

void dijkstra(int start){
	
	d[start] = 0;
	priority_queue<pair<int,int> >pq;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(d[current] < distance) continue;
		for(int i=0; i<a[current].size(); i++){
			int next = a[current][i].second;
			int nextDistance = distance + a[current][i].first;
			if(d[next] > nextDistance){
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next)); 
			}
		}
	} 
}

int main(){
	
	int u,v,w,st,de;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1; i<=N; i++){
		d[i] = INF;
	}
	
	for(int i=0; i<M; i++){
		scanf("%d %d %d",&u,&v,&w);
		a[u].push_back(make_pair(w,v));
	}
	
	scanf("%d %d",&st,&de);
	
	dijkstra(st);
	
	if(d[de] != INF) printf("%d",d[de]);
	else return 0;
	
}
