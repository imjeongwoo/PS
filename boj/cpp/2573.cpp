#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, result, flag;
int g[300][300];
int check[300][300];
int vis[300][300];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

void checkSide() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 0) continue;

            for (int k = 0; k < 4; k++) {
                int x = i + d[k][0];
                int y = j + d[k][1];

                if (!g[x][y]) check[i][j]++; // 옆이 0이면 증가
            }
        }
    }
}

void melt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] && check[i][j]) {
                int val = g[i][j] - check[i][j];
                if (val < 0) g[i][j] = 0;
                else g[i][j] = val;
            }
        }
    }
}

void dfs(int x, int y) {
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];

        if (!vis[nx][ny] && g[nx][ny])
            dfs(nx, ny);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    while (true) {
        memset(check, 0, sizeof(check));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && g[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if (cnt == 0) break;
        if (cnt >= 2) {
            flag = 1;
            break;
        }
        checkSide();
        melt();
        result++;
    }
    if (flag) cout << result;
    else cout << 0;
    return 0;
}