#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int g[101][101];
bool vis[101][101];
int vis2[101][101];

int n, land = 1, mn = 10000;

bool OOB(int x, int y) {
    return x < 0 || x >=  n || y < 0 || y >= n;
}

void divideLand(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    g[x][y] = land;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (OOB(nx, ny) || vis[nx][ny] || g[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            g[nx][ny] = land;
            q.push(make_pair(nx, ny));
        }
    }
}

int bfs(int x, int y, int currentLand) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if (g[x][y] != 0 && g[x][y] != currentLand)
            return vis2[x][y] - 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (OOB(nx, ny) || vis2[nx][ny] || g[nx][ny] == currentLand) continue;
            vis2[nx][ny] = vis2[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return 10000;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && g[i][j]) {
                divideLand(i, j);
                land++;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && g[i][j] > 0) {
                mn = min(bfs(i, j, g[i][j]), mn);
                memset(vis2, 0, sizeof(vis2));
            }
        }
    }
    cout << mn << '\n';
    
    return 0;
}