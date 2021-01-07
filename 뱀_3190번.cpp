#include<iostream>
#include<queue>

using namespace std;

queue<pair<char, pair<int, int>>>store;
queue<pair<int, char>> command;

int N, K, L;
int map[102][102];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int dir_h = 0;
int dir_t = 0;
int TIME = 0;
pair<int, int> tail; // y,x
pair<int, int> head;

int func() {

    while (true) {

        int cnt = TIME;
        int h_y = head.first;
        int h_x = head.second;
        int t_y = tail.first;
        int t_x = tail.second;
        int T;
        char input;

        if (!command.empty()) {
            T = command.front().first;
            input = command.front().second;
            command.pop();
        }
        else {
            T = 987654321;
            input = 'a';
        }
        

        while (cnt < T) {

            cnt++;
            TIME++;

            h_y += dy[dir_h];
            h_x += dx[dir_h];

            if (h_y > N || h_y<1 || h_x>N || h_x < 1 || map[h_y][h_x] == 8) return -1;

            if (map[h_y][h_x] == 0) { // 사과가 없다면
                map[t_y][t_x] = 0;

                if (!store.empty() && store.front().second.first == t_y && store.front().second.second == t_x) {
                    if (store.front().first == 'L') {
                        dir_t = dir_t - 1;
                        if (dir_t == -1) dir_t = 3;
                    }
                    else if (store.front().first == 'D') {
                        dir_t = (dir_t + 1) % 4;
                    }
                    store.pop();
                }
                t_y += dy[dir_t];
                t_x += dx[dir_t];
            }

            map[h_y][h_x] = 8;

        }
        store.push({ input, {h_y,h_x} });

        head.first = h_y;
        head.second = h_x;
        tail.first = t_y;
        tail.second = t_x;

        if (input == 'L') {
            dir_h = dir_h - 1;
            if (dir_h == -1) dir_h = 3;
        }
        else if (input == 'D') {
            dir_h = (dir_h + 1) % 4;
        }

    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        map[a][b] = true;
    }

    cin >> L;

    char input;
    head = { 1,1 };
    tail = { 1,1 };
    map[1][1] = 8;

    for (int i = 0; i < L; i++) {
        cin >> a >> input;
        command.push({ a,input });
    }
    
    func();

    cout << TIME;



}