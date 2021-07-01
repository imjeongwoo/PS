#include <bits/stdc++.h>
using namespace std;

// 동, 북, 서, 남
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m;
int g[9][9];
int g2[9][9];
int check_cctv[8];
int dir[8];
int mn, wall;

vector<pair<int, int> > cctv;

bool isOk(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void go(int x, int y, int d) {
    d %= 4;
    g2[x][y] = 7;

    int nx = x + dx[d];
    int ny = y + dy[d];

    while (isOk(nx, ny) && g[nx][ny] != 6) {
        g2[nx][ny] = 7;
        nx += dx[d];
        ny += dy[d];
    }
}

void move(int x, int y, int d) {
    if (g[x][y] == 1) {
        go(x, y, d);
    }
    else if (g[x][y] == 2) {
        go(x, y, d);
        go(x, y, d + 2);
    }
    else if (g[x][y] == 3) {
        go(x, y, d);
        go(x, y, d + 1);
    }
    else if (g[x][y] == 4) {
        go(x, y, d);
        go(x, y, d + 1);
        go(x, y, d + 2);
    }
    else if (g[x][y] == 5) {
        go(x, y, d);
        go(x, y, d + 1);
        go(x, y, d + 2);
        go(x, y, d + 3);
    }
}

void dfs(int k) {
    if (k == cctv.size()) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                g2[i][j] = g[i][j];

        for (int i = 0; i < cctv.size(); i++)
            move(cctv[i].first, cctv[i].second, dir[i]);

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g2[i][j] == 0) cnt++;
        mn = min(mn, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        dir[k] = i;
        dfs(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    mn = m * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];    
            if (g[i][j] != 0 && g[i][j] != 6) {
                cctv.push_back(make_pair(i, j));
            } else if (g[i][j] == 6) wall++;
        }
    }
    mn -= wall + cctv.size();
    dfs(0);
    cout << mn;

    return 0;
}