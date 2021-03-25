#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int vis[9];
int result[9];
int pr;
void dfs(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!vis[i] && pr <= arr[i]) {
            result[k] = arr[i];
            pr = result[k];
            dfs(k + 1);
            pr = result[k];

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
