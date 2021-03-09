#include <bits/stdc++.h>
using namespace std;

int t, l;
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
int vis[300][300];
int stx, sty, dstx, dsty;

int bfs(int a, int b) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(a, b));
    vis[a][b] = 1;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        if (x == dstx && y == dsty) return vis[x][y] - 1;
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = vis[x][y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while (t--) { 
        cin >> l;
        cin >> stx >> sty;
        cin >> dstx >> dsty;
        cout << bfs(stx, sty) << '\n';
        for (int i = 0; i < 300; i++)
            fill(vis[i], vis[i] + 300, 0);
    }
    return 0;
}