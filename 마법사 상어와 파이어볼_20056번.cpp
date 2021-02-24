#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M, K;
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int dir_e[] = { 0,2,4,6 };
int dir_o[] = { 1,3,5,7 };

typedef struct fire_ {
    int y;
    int x;
    int mass;
    int s;
    int dir;
}fire;

vector<fire> f;

void move_fire() {

    vector<vector<fire>> v;
    for (int k = 0; k < M; k++) {
        vector<fire> store;
        int ny = f[k].y + f[k].s * dy[f[k].dir];
        int nx = f[k].x + f[k].s * dx[f[k].dir];
        if (nx >= 1 && nx <= N) f[k].x = nx;
        else {
            if (nx > N) {
                if (nx % N == 0) f[k].x = N;
                else  f[k].x = nx % N;
            }
            if (nx < 1) f[k].x = N - (abs(nx) % N);
        }

        if (ny >=1  && ny <= N) f[k].y = ny;
        else {
            if (ny > N) {
                if (ny % N == 0) f[k].y = N;
                else  f[k].y = ny % N;
            }
            if (ny < 1) f[k].y = N  - (abs(ny) % N);
        }

        store.push_back({ f[k].y,f[k].x,f[k].mass,f[k].s,f[k].dir });

        if (v.size() == 0) {
            v.push_back(store);
            continue;
        }

        int cnt = v.size();
        for (int a = 0; a < cnt; a++) {
            if (v[a].size() != 0) {
                if (v[a][0].x == f[k].x && v[a][0].y == f[k].y) {
                    v[a].push_back({ f[k].y,f[k].x,f[k].mass,f[k].s,f[k].dir });
                    break;
                }                
            }
            
            if (a == v.size() - 1) {
                v.push_back(store);
                break;
            }
         }
    }
    f.clear();

    // 겹치는 파이어볼 처리
    for (int a = 0; a < v.size(); a++) {

        int sum_m = 0;
        int sum_s = 0;
        int sum_dir = 0;

        if (v[a].size() == 1) { //1개일때
            f.push_back({ v[a][0].y,v[a][0].x,v[a][0].mass,v[a][0].s,v[a][0].dir });
            continue;
        }
        //2개 이상
        int odd = 0;
        for (int b = 0; b < v[a].size(); b++) {
            sum_m += v[a][b].mass;
            sum_s += v[a][b].s;
            odd += v[a][b].dir % 2;
        }
        
       

        sum_m = sum_m / 5;
        sum_s = sum_s / v[a].size();
        if (sum_m == 0) {
            M = M - (v[a].size());
            continue; // 질량이 0이면 파이어볼은 소멸
        }

        M = M - v[a].size() + 4;
        for (int i = 0; i < 4; i++) {
            if (odd ==0 || odd == v[a].size()) { // 모두 짝수이거나 홀수일때
                f.push_back({ v[a][0].y, v[a][0].x,sum_m,sum_s,dir_e[i] });
            }
            else f.push_back({ v[a][0].y, v[a][0].x,sum_m,sum_s,dir_o[i] });
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // N x N 격자 파이어볼 M
    // 질량,방향,속력, 위치
    // 자신의 방향으로 속력 만큼 이동
    // 2개 이상의 파이어볼이 있는 칸
    // 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다. 
    // 나누어진 파이어볼의 
    // 질량 질량의합/ 5
    // 속력의 합 / 합쳐진 파이어볼의 개수
    // 모두 홀수이거나, 모두 짝수이면 방향 0,2,4,6
    // 그렇지 않으면 1,3,5,7
    // 질량이 0인 파이어볼은 소멸되어진다.
    // 이동 k번후 남아있는 파이어볼 질량의 합


    cin >> N >> M >> K;
    int y_, x_, ma, sp, di;
    for (int i = 0; i < M; i++) { //y,x,질량,속력,방향
        cin >> y_ >> x_ >> ma >> sp >> di;
        f.push_back({ y_,x_,ma,sp,di });
    }

    for (int p = 1; p <= K; p++) {
        move_fire();
    }

    int ans = 0;
    for (int i = 0; i < f.size(); i++) ans += f[i].mass;

    cout << ans;
}