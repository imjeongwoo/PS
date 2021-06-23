#include <bits/stdc++.h>
using namespace std;

int n;
int minimum = INT32_MAX;
int vis[21];
int stat[21][21];

void dfs(int k, int start) {
    if (k == n / 2) {
        int st = 0, lnk = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[i] && vis[j]) st += stat[i][j];
                else if (!vis[i] && !vis[j]) lnk += stat[i][j];
            }
        }
        minimum = (minimum < abs(st - lnk)) ? minimum : abs(st - lnk);
        return;
    }

    for (int i = start; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(k + 1, i + 1);
        vis[i] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> stat[i][j];
    
    dfs(0, 1);

    cout << minimum;

    return 0;
}