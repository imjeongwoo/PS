#include <bits/stdc++.h>
using namespace std;

// f: 총 몇층?  1 ~ (1e6)
// s: 현재위치
// g: 목표점

int f, s, g, u, d, result;
int vis[int(1e6) + 1];

int bfs(int cur) {
    queue<int> q;
    int dx[2] = {u, -d};

    vis[cur] = 1;
    q.push(cur);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == g) {
            return vis[x] - 1;
        }

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];

            if (nx < 1 || nx > f) continue;
            if (vis[nx]) continue;

            vis[nx] = vis[x] + 1;
            q.push(nx);
        }

    }
    return -1;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> f >> s >> g >> u >> d;

    result = bfs(s);

    if (result == -1) cout << "use the stairs";
    else cout << result;

    return 0;
}