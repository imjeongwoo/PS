#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
int vis[1001];
vector<int> graph[1001];
void dfs(int u);

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!vis[v]) dfs(v);
    }
}