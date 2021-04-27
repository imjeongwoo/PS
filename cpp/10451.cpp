#include <bits/stdc++.h>

using namespace std;

int t, n, cnt;
int arr[1001];
int vis[1001];

void dfs(int root, int k) {
    if (vis[k] && root == k) {
        cnt++;
        return;
    } else if (vis[k])
        return;

    vis[k] = 1;
    dfs(root, arr[k]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                dfs(i, i);
        }
        cout << cnt << '\n';
        memset(vis, 0, sizeof(vis));
        cnt = 0;
    }
    return 0;
} 