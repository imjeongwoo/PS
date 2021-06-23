#include <bits/stdc++.h>
using namespace std;

int k, pr;
int num[13];
int vis[13];
int result[6];

void dfs(int n) {
    if (n == 6) {
        for (int i = 0; i < 6; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0 ; i < k; i++) {
        if (!vis[i] && pr < num[i]) {
            pr = num[i];
            result[n] = num[i];
            vis[i] = 1;
            dfs(n + 1);
            vis[i] = 0;
            pr = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> k && k) {
        for (int i = 0; i < k; i++)
            cin >> num[i];
        dfs(0);
        cout << '\n';
    }
    return 0;
}