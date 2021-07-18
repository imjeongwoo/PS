#include <bits/stdc++.h>
using namespace std;

int r, c;
int mx;
int vis[20][20];
int isUsed[26];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1 ,1, 0, 0};
vector<string> g;

bool OOB(int x, int y) {
    return x < 0 or x >= r or y < 0 or y >= c;
}

void dfs(int x, int y, int depth) {
    mx = max(mx, depth);
    vis[x][y] = 1;
    isUsed[g[x][y] - 'A'] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!OOB(nx, ny) and !vis[nx][ny] and !isUsed[g[nx][ny] - 'A']) {
            dfs(nx, ny, depth + 1);
            vis[nx][ny] = 0;
            isUsed[g[nx][ny] - 'A'] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string tmp; cin >> tmp;
        g.push_back(tmp);
    }
    dfs(0, 0, 1);
    cout << mx << '\n';
    return 0;
}