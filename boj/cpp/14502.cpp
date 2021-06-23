#include <bits/stdc++.h>
using namespace std;

int n, m, result;
int g[8][8];
int vis[8][8];

int bfs() {
    queue<pair<int, int> > q;
    int d[4][2] = {{0, 1} ,{0, -1}, {1, 0}, {-1, 0}};
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 2) q.push(make_pair(i, j));
    
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] || vis[nx][ny]) continue;

            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    // 바이러스 전파 완료후 안전영역 구하기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 0 && vis[i][j] == 0) cnt++;

    return cnt;
}

void makeWall(int k) {
    if (k == 3) {
        memset(vis, 0, sizeof(vis));
        result = max(result, bfs()); // 최대 크기 갱신
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) continue;
            g[i][j] = 1; // 벽을 세우고
            makeWall(k + 1);
            g[i][j] = 0; // 벽 다시 없애줌
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > q;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    makeWall(0);
    cout << result;

    return 0;
}