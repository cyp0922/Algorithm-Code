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

    // 0 ��� 1���� 2�Ķ�

    for (int k = 0; k < horse.size(); k++) {

        int dir = horse[k].second - 1;
        int y = horse[k].first.first;
        int x = horse[k].first.second;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx] == 0) { // ���

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
        else if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx] == 1) {// ����

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
        else if (nx <1 || nx > N || ny <1 || ny >N || map[ny][nx] == 2) { // ���̳� �Ķ���

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

    // ���� ���� K��, ���� ���Ǹ��, �ϳ��� �� ���� �ٸ� ���� �ø� �� �մ�.
    // �Ķ��� , ������ , ������� ĥ�����ִ�. 

    // �̵� ���⵵ �̸� �������ִ�. �����¿�
    // 1~K�� �� ���� ������� �̵�
    // �Ѹ��� �̵��� �� ���� �÷��� �ִ� ���� �Բ� �̵�
    // ���� ����Ǵ� �߿� ���� 4�� �̻� ���̸� ���� ����
    // ��� ���������� �������� ���� �÷����´�.
    // ���� A�� ���� ������ �ִ� ��� ���� �׿��ִ� ������ �ݴ�� �ٲ۴�. 
    // �Ķ����� ��� A�� ���� �̵������� �ݴ���ϰ� ��ĭ�̵� 
    // ������ �ݴ�� �ٲ� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵������ʰ� ������
    // ü������ ����� ��쿡�� �Ķ����� ������� 
    // 0 ��� 1���� 2�Ķ�

    // ��, �� , �̵�����

    // ������ �� ���� 4�̻� / cnt == 4 �϶��� Ʋ����

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