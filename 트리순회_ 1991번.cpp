#include<iostream>

using namespace std;

int N;
int tree[27][2];

void pre(int x) {

    if (x != '.' - 'A') {
        printf("%c", x + 'A');
    }
    else return;

    pre(tree[x][0]);
    
    pre(tree[x][1]);

}

void mid(int x) {

    if (x == '.' - 'A') return;

    mid(tree[x][0]);

    if (x != '.' - 'A') {
        printf("%c", x + 'A');
    }


    mid(tree[x][1]);

}

void last(int x) {

    if (x == '.' - 'A') return;

    last(tree[x][0]);

    last(tree[x][1]);

    if (x != '.' - 'A') {
        printf("%c", x + 'A');
    }

}

int main() {

    char a, b, c;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        tree[a - 'A'][0] = b - 'A';
        tree[a - 'A'][1] = c - 'A';
    }

    pre(0);
    cout << endl; 
    mid(0);
    cout << endl;
    last(0);
}