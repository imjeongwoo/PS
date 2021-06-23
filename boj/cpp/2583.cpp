#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int graph[100][100];

int bfs(int a, int b) {
    queue<pair<int, int> > Q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int W = 1;
    graph[a][b] = 1;
    Q.push(make_pair(a, b));

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (graph[nx][ny]) continue;

            graph[nx][ny] = 1;
            W += 1;
            Q.push(make_pair(nx, ny));
        }
    }
    return W;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int bx, by, ex, ey;
        cin >> bx >> by >> ex >> ey;
        for (int j = bx; j < ex; j++) {
            for (int l = by; l < ey; l++) {
                graph[l][j] = 1;
            }
        }
    }


    vector<int> v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!graph[i][j]) {
                v.push_back(bfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int s : v) cout << s << ' ';
    return 0;
}