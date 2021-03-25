#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int vis[10001];
int result[9];

void dfs(int k, int startIndex) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = startIndex; i < n; i++) {
        if(!vis[i]) {
            result[k] = arr[i];
            vis[i] = 1;
            dfs(k + 1, i + 1);
            vis[i] = 0;
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
    dfs(0, 0);

    return 0;
}
