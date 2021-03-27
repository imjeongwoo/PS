#include <bits/stdc++.h>
using namespace std;

int n, k, x, cnt;
int M[101][101];
queue<pair<int, char> > cmd;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        M[a][b] = 1; // 사과
    }

    cin >> x;
    for (int i = 0; i < x; i++) {
        int a;
        char b;
        cin >> a >> b;
        cmd.push(make_pair(a, b));
    }

    int x = 1, y = 1;
    int dx = 0, dy = 1;
    queue<pair<int, int> > q;
    M[x][y] = -1;
    q.push(make_pair(x, y));

    while (true) {    
        cnt++;
        x += dx;
        y += dy;

        if (x <= 0 || x > n || y <= 0 || y > n || M[x][y] == -1) break;

        if (M[x][y] != 1) {
            M[q.front().first][q.front().second] = 0;
            q.pop();
        }
        M[x][y] = -1;
        q.push(make_pair(x, y));
        

        if (cmd.front().first == cnt) {
            if (cmd.front().second == 'L') {
                if (dx == 0 && dy == 1) {
                    dx = -1;
                    dy = 0;
                } else if (dx == 1 && dy == 0) {
                    dx = 0;
                    dy = 1;
                } else if (dx == 0 && dy == -1) {
                    dx = 1;
                    dy = 0;
                } else if (dx == -1 && dy == 0) {
                    dx = 0;
                    dy = -1;
                }
            } else {
                if (dx == 0 && dy == 1) {
                    dx = 1;
                    dy = 0;
                } else if (dx == 1 && dy == 0) {
                    dx = 0;
                    dy = -1;
                } else if (dx == 0 && dy == -1) {
                    dx = -1;
                    dy = 0;
                } else if (dx == -1 && dy == 0) {
                    dx = 0;
                    dy = 1;
                }
            }
        cmd.pop();
        }

    }

    cout << cnt;
    return 0;
}