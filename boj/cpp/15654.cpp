#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int vis[10001];
int result[9];

void dfs(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!vis[arr[i]]) {
            result[k] = arr[i];
            vis[arr[i]] = 1;
            dfs(k + 1);
            vis[arr[i]] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    dfs(0);
    return 0;
}
