#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N,E,v1,v2;
int INF = 987654321;

vector <pair<int,int> >star[801];
int d[801];
int d_v1[801];
int d_v2[801];

void dijkstra(int start){
	
	priority_queue<pair<int,int> >pq;
	d[start] = 0;
	pq.push(make_pair(0,start));

	while(!pq.empty()){
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(d[current] < distance) continue;
		
		for(int i=0; i<star[current].size(); i++){
			int next = star[current][i].first;
			int nextDistance = star[current][i].second + distance;
			if(nextDistance < d[next]  ){

				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next));
				
			}
		}
	}
}

void solution(){
	
	for(int i=1; i<=N; i++) d[i] = INF;
	dijkstra(1);
	double v1_route = d[v1];
	double v2_route = d[v2];
	
	for(int i=1; i<=N; i++) d[i] = INF;
	dijkstra(v1);
	v1_route = v1_route + d[v2];
	v2_route = v2_route + d[v2] + d[N];

	for(int i=1; i<=N; i++) d[i] = INF;
	dijkstra(v2);
	v1_route = v1_route + d[N];

 	if(v1_route >=INF && v2_route >=INF) cout << "-1";
	else cout << min(v1_route,v2_route);
	
}

int main(){
	int a,b,c;
	
	cin >> N >> E;
	for(int i=0; i<E; i++){
		cin >> a>>b>>c;
		star[a].push_back(make_pair(b,c));
		star[b].push_back(make_pair(a,c));
	}
	cin >> v1 >> v2;
	
	
	solution();
	
}

