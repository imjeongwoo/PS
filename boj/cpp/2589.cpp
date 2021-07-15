#include <bits/stdc++.h>
using namespace std;

int vis[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
string g[51];
int n, m, answer;

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    int maxShortest = vis[x][y] = 1;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second; q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny) || vis[nx][ny] != 0 || g[nx][ny] != 'L') continue;
            maxShortest = vis[nx][ny] = vis[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return maxShortest - 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
                memset(vis, 0, sizeof(vis));
            }
        }
    }
    cout << answer;
        
    return 0;
}