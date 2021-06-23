#include <bits/stdc++.h>
using namespace std;

int n, m, mx, s;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1,0 , 0};
int g[500][500];
int vis[500][500];

void dfs(int x, int y, int k, int s) {
    vis[x][y] = 1;
    s += g[x][y];

    if (k == 4) {
        mx = (mx > s) ? mx : s;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x +dx[i];
        int ny = y +dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (vis[nx][ny]) continue;
        dfs(nx, ny, k + 1, s);
        vis[nx][ny] = 0;
    }

    if (k == 1) {
        if (x + 1 < n && x - 1 >= 0) { // 위, 아래 
            s += g[x + 1][y] + g[x - 1][y];
            if (y + 1 < m) mx = (mx > s + g[x][y + 1]) ? mx : s + g[x][y + 1];
            if (y - 1 >= 0)  mx = (mx > s + g[x][y - 1]) ? mx : s + g[x][y - 1];
            
            s -= g[x + 1][y] + g[x - 1][y];
        }

        if (y +1 < m && y - 1 >= 0) {// 양옆
            s += g[x][y + 1] + g[x][y - 1];
            if (x + 1 < n) mx = (mx > s + g[x + 1][y]) ? mx : s + g[x + 1][y];
            if (x - 1 >= 0) mx = (mx > s + g[x - 1][y]) ? mx : s + g[x - 1][y];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, 0);
            vis[i][j] = 0;
        }
    }
    cout << mx;

    return 0;
}