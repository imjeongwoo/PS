#include <bits/stdc++.h>
using namespace std;

int n, r1, r2;
char m1[101][101];
char m2[101][101];
int vis[101][101];

void bfs(int a, int b, char m[][101]) {
    queue<pair<int, int> > Q;
    int dx[4] = {0 ,0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vis[a][b] = 1;
    Q.push(make_pair(a, b));

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || m[x][y] != m[nx][ny]) continue;

            vis[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }
    
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m1[i][j];
            if (m1[i][j] == 'G') m2[i][j] = 'R';
            else m2[i][j] = m1[i][j];
        }
    }

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, m1);
                r1++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);
    
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bfs(i, j, m2);
                r2++;
            }
        }
    }
    cout << r1 << ' ' << r2 << '\n';
    return 0;
}