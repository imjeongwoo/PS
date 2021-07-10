#include <bits/stdc++.h>
using namespace std;

int n;
int parent[100001];
vector<int> g[100001];
bool vis[100001];

void dfs(int p) {
    vis[p] = true;
    for (int& child : g[p]) {
        if (!vis[child]) {
            parent[child] = p;
            dfs(child);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
        
    return 0;
}