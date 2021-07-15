#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
vector<pair<int, int> > g[100001];
int v, maxLen, goal;

void dfs(int n, int currentLen) {
    vis[n] = true;
    if (currentLen > maxLen) {
        goal = n;
        maxLen = currentLen;
    }
    for (int i = 0; i < g[n].size(); i++) {
        int next = g[n][i].first, len = g[n][i].second;
        if (!vis[next]) dfs(next, currentLen + len);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;

    for (int i = 0; i < v; i++) {
        int a, b, c, cnt = 0;
        cin >> a;
        while (1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            g[a].push_back(make_pair(b, c));
            g[b].push_back(make_pair(a, c));
        }
    }
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    maxLen = 0;
    dfs(goal, 0);

    cout << maxLen;
    return 0;
}