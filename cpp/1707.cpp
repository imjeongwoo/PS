#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[20001];
int vis[20001];
int t, v, e;

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    vis[v] = 1;

    while (!Q.empty()) {
        int parent = Q.front();
        Q.pop();
        int color = vis[parent];
        int childColor;

        if (color % 2) childColor = 2;
        else childColor = 1;

        for (int child : graph[parent]) {
            if (!vis[child]) {
                vis[child] = childColor;
                Q.push(child);
            }
        }
    }
}

bool isTrue() {
    for (int i = 1; i <= v; i ++) {
        for(int v : graph[i]) {
            if (vis[i] == vis[v]) return 0;
        }
    }
    return 1;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i ++) {
        cin >> v >> e;
        
        for (int j = 0; j < e; j++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int j = 1; j <= v; j++) {
            if (!vis[j]) {
                bfs(j);
            }
        }

        if (isTrue()) cout << "YES\n";
        else cout << "NO\n";
        
        fill(vis, vis + v + 1, 0);
        for (int j = 1; j <= v; j++) {
            graph[j].clear();
        }
    } 
    return 0;
}

// 이미 방문했던 곳이 내 부모가 아니다? 그러면 싸이클이 있다.