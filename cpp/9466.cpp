#include <bits/stdc++.h>
using namespace std;

int t, n;
int vis[100001];
int check[100001];
int wish[100001];
int cnt;

void dfs(int d) {
    vis[d] = 1;
    int next = wish[d];
    if (!vis[next]) dfs(next);
    else if (vis[next] && !check[next]) {
        for (int i = next; i != d; i = wish[i])
            cnt--;
        cnt--;
    }
    check[d] = 1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        
        cnt = n;
        for (int j = 1; j <= n; j++)
            cin >> wish[j];
        
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) dfs(j);
        }
        cout << cnt << '\n';
        for (int j = 1; j <=n; j++) vis[j] = check[j] = 0;
    }
    return 0;
}