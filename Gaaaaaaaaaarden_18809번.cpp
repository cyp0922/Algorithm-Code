#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, G, R;
int arr[51][51];
int map[2][51][51];
bool visited[51][51];
int MAX = 0;

struct is {
    int y;
    int x;
    int cnt;
    int color;
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector<pair<int, int>> r;
vector<pair<int, int>> g;
queue<is> q;

void print() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << map[0][y][x];
        }
        cout << endl;
    }
    cout << endl;

}

int bfs() {
    // red 0 ,green 1
    int flower = 0;
    while (!q.empty()) {

        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        int color = q.front().color;
        q.pop();

        if (map[0][y][x] == 3) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {

                if (map[0][ny][nx] != 3 && map[0][ny][nx] != color && map[1][ny][nx] == cnt + 1) { // 꽃 만들때
                    flower++;
                    map[0][ny][nx] = 3;
                    continue;
                }
                else if (!visited[ny][nx] && arr[ny][nx] != 0) {
                    visited[ny][nx] = true;
                    map[0][ny][nx] = color;
                    map[1][ny][nx] = cnt + 1;
                    q.push({ ny,nx,cnt + 1,color });
                }
            }
        }
    }
    return flower;
}

void func(int cy, int cx, int green, int red) {

    if (green == G && red == R) {

        memset(visited, false, sizeof(visited));
        memset(map, false, sizeof(map));

        q = queue<is>();
        for (int i = 0; i < r.size(); i++) {
            q.push({ r[i].first,r[i].second, 0,1 });
            map[0][r[i].first][r[i].second] = 1; // red
            visited[r[i].first][r[i].second] = true;
        }
        for (int i = 0; i < g.size(); i++) {
            q.push({ g[i].first,g[i].second, 0,2 });
            map[0][g[i].first][g[i].second] = 2; // green
            visited[g[i].first][g[i].second] = true;
        }

        int num = bfs();
        MAX = max(num, MAX);
        return;
    }

    for (int y = cy; y < N; y++) {
        for (int x = cx; x < M; x++) {
            if (arr[y][x] == 2) {
                if (red + 1 <= R) {
                    r.push_back({ y,x });
                    func(y, x + 1, green, red + 1);
                    r.pop_back();
                }
                if (green + 1 <= G) {
                    g.push_back({ y,x });
                    func(y, x + 1, green + 1, red);
                    g.pop_back();
                }
            }
        }
        cx = 0;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> G >> R;
    //0호수 1배양액x 2배양액 o
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> arr[y][x];
        }
    }
    func(0, 0, 0, 0);
    cout << MAX;
}