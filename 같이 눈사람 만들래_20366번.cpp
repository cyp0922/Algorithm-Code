#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int N;
int MIN = 2e9;
int arr[601];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    //10 1 2 3 5 5 7 10 18 30 40
    //ans 0

    // N-1 ,N-2 ,N-3

    int sum1 = 0;
    int sum2 = 0;
    int MIN = 1e9;
    int b;
    for (int i = 0; i < N - 3; i++) {
        for (int j = i + 1; j < N - 2; j++) {
            for (int a = j + 1; a < N - 1; a++) {

                if (a == j + 1) b = a + 1;

                sum1 = arr[i] + arr[b];
                sum2 = arr[j] + arr[a];
                int temp = abs(sum1 - sum2);
                if (a != b) MIN = min(MIN, temp);

                while (b < N-1) {

                    sum1 = arr[i] + arr[b + 1];
                    if (abs(sum1 - sum2) > temp) break;
                    b++;
                    MIN = min(MIN, abs(sum1 - sum2));
                    temp = abs(sum1 - sum2);

                }

            }
        }
    }


    cout << MIN;

}