#include <bits/stdc++.h>
using namespace std;

int n, a, b, m;
int vis[101];
bool flag;
vector<int> v[101];

void dfs(int a, int chon) {
    vis[a] = 1;
    for (int y : v[a]) {
        if (!vis[y]) {
            if (y == b) {
                vis[y] = 1;
                cout << chon + 1;
                flag = true;
                return;
            }
            dfs(y, chon + 1);
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(7, 0);
    if (!flag) cout << -1;

    return 0;
}