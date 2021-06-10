#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int R, C, M;
int arr[101][101];

struct sh {
    int y;
    int x;
    int speed; 
    int dir;
    int size;
    bool live;
};
vector<sh> shark;

int dx[] = { 0,0,1,-1 }; // 위 아래 오른쪽 왼쪽
int dy[] = { -1,1,0,0 };
int rdir[] = { 1,0,3,2 };

void shark_move() {
    
    memset(arr, false, sizeof(arr));

    for (int h = 0; h < M; h++) {
        if (shark[h].live == true) {
            int y = shark[h].y;
            int x = shark[h].x;
            int speed = shark[h].speed;
            int dir = shark[h].dir;
            int size = shark[h].size;

            if (dir == 0 || dir == 1) speed = speed % (2 * (R - 1));
            else speed = speed % (2 * (C - 1));
            int ny = y; int nx = x;
            for (int i = 0; i < speed; i++) {
                int ky = ny + dy[dir];
                int kx = nx + dx[dir];
                if (1 <= ky && ky <= R && 1 <= kx && kx <= C) {
                    ny = ky;
                    nx = kx;
                }
                else {
                    dir = rdir[dir];
                    ny = ny + dy[dir];
                    nx = nx + dx[dir];
                }
            }

            if (arr[ny][nx]) {
                if (size > shark[arr[ny][nx] - 1].size) {
                    shark[arr[ny][nx] - 1].live = 0;
                    arr[ny][nx] = h + 1; 
                    shark[h].y = ny; 
                    shark[h].x = nx;
                    shark[h].dir = dir;
                }
                else {
                    shark[h].live = false; 
                }
            }
            else {
                arr[ny][nx] = h + 1;
                shark[h].y = ny;
                shark[h].x = nx;
                shark[h].dir = dir;
            }
        }
    }
}

int fishing() {

    int sum = 0;

    for (int t = 1; t <= C; t++) {
        // 먼저 잡는다;
        for (int y = 1; y <= R; y++) {
            if (arr[y][t] > 0) {
                sum += shark[arr[y][t] - 1].size;
                shark[arr[y][t] - 1].live = false;
                break;
            }
        }
        // 상어 이동;
        shark_move();
    }
    return sum; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C >> M;

    int r, c, s, d, z;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        shark.push_back({ r,c,s,d - 1,z,1 });
        arr[r][c] = i + 1;
    }
    cout << fishing();
}