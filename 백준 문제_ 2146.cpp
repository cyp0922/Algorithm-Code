#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int map[101][101];
int visited[101][101];
bool NEW[101][101];
int N;
int cnt = 1;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

queue<pair<int, int>> store;

void bfs(int y_, int x_) {

    queue<pair<int, int>> q;
    q.push({ y_,x_ });
    visited[y_][x_] = cnt;

    while (!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {

                if (map[n_y][n_x] == 0) {
                    if (store.empty())  store.push({ y,x });
                    if (!store.empty() && store.back().first == y && store.back().second == x) continue;
                    else store.push({ y,x }); // 중복 방지
                }

                if (map[n_y][n_x] && !visited[n_y][n_x]) {
                    visited[n_y][n_x] = cnt;
                    q.push({ n_y,n_x });
                }
            }

        }


    }

}

int rebfs(int color, int y_, int x_) {

    queue< pair< int, pair<int, int> > >  q;
    q.push({ 0 , { y_,x_ } });
    NEW[y_][x_] = true;

    while (!q.empty()) {
        int num = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {

                if (color != visited[n_y][n_x] && visited[n_y][n_x] != 0) { // 다른 대륙을 만났을 때
                    return num;
                }

                if (!NEW[n_y][n_x] && color != visited[n_y][n_x]) {
                    NEW[n_y][n_x] = true;
                    q.push({ num + 1,{ n_y,n_x } });
                }
            }

        }
    }

    return 987654321;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int small = 987654321;

    cin >> N;

    // 입력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }
    //

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x] && map[y][x]) {
                bfs(y, x);
                cnt++;
            }
        }
    }

    while (!store.empty()) {

        int a = store.front().second;
        int b = store.front().first;
        store.pop();
        small = min(small, rebfs(visited[b][a], b, a));
        memset(NEW, false, sizeof(NEW));

    }


    cout << small;

    return 0;

}