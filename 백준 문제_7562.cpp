#include<iostream>
#include<queue>
#include<algorithm>

using namespace std; 

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int map[301][301] = {0,};
int visited[301][301] = {0,};
struct m{
	int x;
	int y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t_case,m_size,s_x,s_y,d_x,d_y;
	cin >> t_case;
	
	for(int i=0; i<t_case; i++){
		cin >> m_size;
		
		cin >> s_x >> s_y >> d_x >> d_y;
		
		queue<m> q;
		q.push({s_x,s_y});
		visited[s_x][s_y] = true;
		
		while(!q.empty()){
			
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			
			if(x== d_x && y == d_y) break;
			
			for(int k=0; k<8; k++){
				int new_x = x + dx[k];
				int new_y = y + dy[k];
				
				if(new_x>=0 && new_x < m_size && new_y >=0 && new_y < m_size && !visited[new_x][new_y] ){
					visited[new_x][new_y] = visited[x][y] + 1;
					q.push({new_x,new_y});
					
				}
			}
		}
		
		cout << visited[d_x][d_y]-1<< endl;
		
		for(int a=0; a < m_size; a++){
			for(int b=0; b<m_size; b++){
				cout<< visited[a][b] << " ";
				visited[a][b] =0;
				
			}
			cout << endl;
		}
		
		
	} 
}
