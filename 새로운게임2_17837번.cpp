#include<iostream>
#include<vector>
using namespace std;

int N, K;
int map[13][13];
int num[13][13][12];
int cnt[13][13];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0 ,-1,1 };

vector<pair<pair<int, int>, int>> horse;

int move() {

    // 0 흰색 1빨강 2파랑

    for (int k = 0; k < horse.size(); k++) {

        int dir = horse[k].second - 1;
        int y = horse[k].first.first;
        int x = horse[k].first.second;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx] == 0) { // 흰색

            int temp = 0;
            for (int i = 1; i <= cnt[y][x]; i++) {
                if (num[y][x][i] == k + 1) {
                    temp = i;
                    break;
                }
            }

            int idx = 1;
            for (int i = temp; i <= cnt[y][x]; i++) {

                num[ny][nx][cnt[ny][nx] + idx] = num[y][x][i];
                horse[num[y][x][i] - 1].first.first = ny;
                horse[num[y][x][i] - 1].first.second = nx;
                num[y][x][i] = 0;
                idx++;
            }
            cnt[ny][nx] += idx -1 ;
            cnt[y][x] -= idx - 1;
            if (cnt[ny][nx] >= 4) return 1;

        }
        else if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx] == 1) {// 빨강

            int temp = 0;
            for (int i = 1; i <= cnt[y][x]; i++) {
                if (num[y][x][i] == k + 1) {
                    temp = i;
                    break;
                }
            }

            int idx = 1;

            for (int i = cnt[y][x]; i >= temp; i--) {

                num[ny][nx][cnt[ny][nx] + idx] = num[y][x][i];
                horse[num[y][x][i] - 1].first.first = ny;
                horse[num[y][x][i] - 1].first.second = nx;
                num[y][x][i] = 0;
                idx++;
            }
            cnt[ny][nx] += idx-1;
            cnt[y][x] -= idx - 1;
            if (cnt[ny][nx] >= 4) return 1;

        }
        else if (nx <1 || nx > N || ny <1 || ny >N || map[ny][nx] == 2) { // 밖이나 파란색

            int temp = 0;
            for (int i = 1; i <= cnt[y][x]; i++) {
                if (num[y][x][i] == k + 1) {
                    temp = i;
                    break;
                }
            }
            if (dir == 0 || dir == 1) dir = (dir + 1) % 2; 
            else if (dir == 2) dir = 3;
            else if (dir == 3) dir = 2;

            ny = y + dy[dir];
            nx = x + dx[dir];
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= N ) {

                int idx = 1;
                if (map[ny][nx] == 0) {
                    for (int i = temp; i <= cnt[y][x]; i++) {

                        num[ny][nx][cnt[ny][nx] + idx] = num[y][x][i];
                        horse[num[y][x][i] - 1].first.first = ny;
                        horse[num[y][x][i] - 1].first.second = nx;
                        num[y][x][i] = 0;
                        idx++;
                    }
                    cnt[ny][nx] += idx - 1;
                    cnt[y][x] -= idx - 1;
                }
                else if (map[ny][nx] == 1) {

                    for (int i = cnt[y][x]; i >= temp; i--) {

                        num[ny][nx][cnt[ny][nx] + idx] = num[y][x][i];
                        horse[num[y][x][i] - 1].first.first = ny;
                        horse[num[y][x][i] - 1].first.second = nx;
                        num[y][x][i] = 0;
                        idx++;
                    }
                    cnt[ny][nx] += idx - 1;
                    cnt[y][x] -= idx - 1;
                }

                if (cnt[ny][nx] >= 4) return 1;
            }
            horse[k].second = dir + 1;
        }

    }

    return 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 말의 개수 K개, 말은 원판모양, 하나의 말 위에 다른 말을 올릴 수 잇다.
    // 파란색 , 빨간색 , 흰색으로 칠해져있다. 

    // 이동 방향도 미리 정해져있다. 상하좌우
    // 1~K번 말 까지 순서대로 이동
    // 한말이 이동할 때 위에 올려져 있는 말도 함께 이동
    // 턴이 진행되던 중에 말이 4개 이상 쌓이면 게임 종료
    // 흰색 말이있으면 가장위에 말을 올려놓는다.
    // 빨강 A번 말과 그위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다. 
    // 파란색인 경우 A번 말의 이동방향을 반대로하고 한칸이동 
    // 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지않고 가만히
    // 체스판을 벗어나는 경우에는 파란색과 같은경우 
    // 0 흰색 1빨강 2파랑

    // 행, 열 , 이동방향

    // 문제를 잘 읽자 4이상 / cnt == 4 일때는 틀리다

    cin >> N >> K;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) cin >> map[y][x];
    }

    int a, b, c;
    for (int i = 1; i <= K; i++) {
        cin >> b >> a >> c;
        horse.push_back({ {b,a},c });
        num[b][a][1] = i;
        cnt[b][a]++;
    }


    for (int p = 1; p <= 1000; p++) {

        if (move()) {
            cout << p;
            exit(0);
        }
    }
    cout << "-1";


}