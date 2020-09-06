#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int V,E;
vector<pair<int,int> >a[20001];
int d[20001];

int INF = 1000000;

void dijkstra(int start){
	
	d[start] =0;
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
			if(nextDistance < d[next] ){
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next)); 
			}
		}
	}
}

int main(){
	
	int k,u,v,w;
	scanf("%d %d %d",&V,&E,&k);
	
	for(int i=1; i<= V; i++){
		d[i] = INF;
	}
	
	for(int i=0; i<E; i++){
		scanf("%d %d %d",&u,&v,&w);
		a[u].push_back(make_pair(w,v)); 
	}
	
	dijkstra(k);
	
	for(int i=1; i<= V; i++){
		if(d[i] != INF){
			printf("%d\n",d[i]);
		}
		else{
			printf("INF\n");
		}
	}
	
}
