#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,M,X;
int INF = 987654321;
vector<pair<int,int> > dis[1001];
vector<pair<int,int> > r_dis[1001];
int d[1001];
int r[1001];

void dijkstra_1(int start){
	
	priority_queue<pair<int,int> > pq;
	d[start] = 0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(d[current] < distance) continue;
		for(int i=0; i<dis[current].size(); i++){
			int next = dis[current][i].first;
			int nextDistance = dis[current][i].second + distance;
			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next));
			}
		}
	}
}

void dijkstra_2(int start){
	
	priority_queue<pair<int,int> > pq;
	r[start] = 0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(r[current] < distance) continue;
		for(int i=0; i<r_dis[current].size(); i++){
			int next = r_dis[current][i].first;
			int nextDistance = r_dis[current][i].second + distance;
			if(nextDistance < r[next]){
				r[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next));
			}
		}
	}
}

int main(){
	int a,b,c;
	int big =0;
	cin >> N >>M>>X;
	
	for(int i=1; i<=N; i++) r[i] = d[i] = INF;
	
	for(int i=0; i<M; i++){
		cin >> a >> b >> c;
		dis[a].push_back(make_pair(b,c));
		r_dis[b].push_back(make_pair(a,c)); 
	}
	
	dijkstra_1(X);
	dijkstra_2(X);
	
	for(int i=1; i<=N; i++){
		big = max(big,d[i]+r[i]);
	}
	
	cout << big;	
}
