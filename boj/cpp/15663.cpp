#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int result[9];
int vis[9];
int isused[100001];

void dfs(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    int pr = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (pr == arr[i]) continue;
        result[k] = arr[i];
        pr = arr[i];
        vis[i] = 1;
        dfs(k + 1);
        vis[i] = 0;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    dfs(0);
    return 0;
}