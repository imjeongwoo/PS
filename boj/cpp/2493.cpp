#include <bits/stdc++.h>
using namespace std;

int n;
int h[500001];
int result[500001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];

        if (i < 1) continue;
        int front = i - 1;
        if (h[i] > h[front]) {
            while (true) {
                front = result[front];
                if (front == 0 || h[front] >= h[i]) break;
            }
        }
        result[i] = front;
    }
    for (int i = 1; i <= n; i++) cout << result[i] << ' ';

    return 0;
}