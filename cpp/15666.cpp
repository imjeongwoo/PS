#include <bits/stdc++.h>
using namespace std;

int n, m, w;
int arr[7];
int vis[7];
int result[7];

void dfs(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    int pr = 0;
    for (int i = start; i < n; i++) {
        if (pr != arr[i]) {
            pr = arr[i];
            result[k] = arr[i];
            dfs(k + 1, i);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    dfs(0, 0);

    return 0;
}