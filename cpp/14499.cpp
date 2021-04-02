#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int g[20][20];
int d[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int v[4];
int h[3];
queue<int> cmd;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    for (int i  = 0; i < k; i++) {
        int c; cin >> c;
        cmd.push(c);
    }

    while(!cmd.empty()) {
        int c = cmd.front(); cmd.pop();
        int nx = x + d[c][0];
        int ny = y + d[c][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        int tmp = v[3];
        switch (c) {
            case 1:
                v[3] = h[2];
                h[2] = h[1];
                h[1] = h[0];
                h[0] = tmp;
                v[1] = h[1];
                break;
            case 2:
                v[3] = h[0];
                h[0] = h[1];
                h[1] = h[2];
                h[2] = tmp;
                v[1] = h[1];
                break;
            case 3:
                v[3] = v[0];
                v[0] = v[1];
                v[1] = v[2];
                v[2] = tmp;
                h[1] = v[1];
                break;
            case 4:
                v[3] = v[2];
                v[2] = v[1];
                v[1] = v[0];
                v[0] = tmp;
                h[1] = v[1];
                break;
        }
        x = nx; y = ny;

        if (g[x][y] == 0) g[x][y] = v[3];
        else {
            v[3] = g[x][y];
            g[x][y] = 0;
        }

        cout << v[1] << '\n';
    }

    return 0;
}