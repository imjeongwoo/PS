#include <bits/stdc++.h>
using namespace std;

int n, mx, high, result;
int m[100][100];
int vis[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};

void bfs(int x, int y, int k) {
    queue<pair<int, int> > q;

    vis[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] || m[nx][ny] <= k) continue;

            vis[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
            high = max(high, m[i][j]);
        }
    }

    
    for (int k = 0; k < high; k++) {
        for (int i = 0; i < n; i++) {
             for(int j = 0; j < n; j++) {
                 if (m[i][j] > k && !vis[i][j]) {
                    bfs(i, j, k);
                    result++;
                 }
            }
        }
        mx = max(mx, result);
        result = 0;
        memset(vis, 0, sizeof(vis));
    }
    cout << mx; 

    return 0;
}