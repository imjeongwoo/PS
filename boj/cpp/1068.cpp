#include <bits/stdc++.h>
using namespace std;

int n, delNode, rootNode, cnt;
bool vis[50];
vector<int> v[50];

void dfs(int node) {
    vis[node] = true;
    if (v[node].empty() || (v[node].size() == 1 && v[node][0] == delNode)) {
        cnt++;
        return;
    }
    for (int i = 0; i < v[node].size(); i++)
        if (!vis[v[node][i]] && v[node][i] != delNode)
            dfs(v[node][i]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int root; cin >> root;
        if (root == -1) rootNode = i;
        else v[root].push_back(i);
    }
    cin >> delNode; v[delNode].clear();

    if (rootNode != delNode)
        dfs(rootNode);
    cout << cnt;
    return 0;
}