#include <bits/stdc++.h>
using namespace std;

int n;
int arr[12];
int vis[12];
int token[4];
int mn = INT32_MAX, mx =INT32_MIN;

void dfs(int k) {
    if (k == n - 1) {
        int result = arr[0];
        for (int i = 1; i < n; i++) {
            if (vis[i - 1] == 0)
                result += arr[i];
            else if (vis[i - 1] == 1)
                result -= arr[i];
            else if (vis[i - 1] == 2)
                result *= arr[i];
            else if (vis[i - 1] == 3)
                result /= arr[i];
        }
        mn = min(mn, result);
        mx = max(mx, result);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!token[i]) continue;
        vis[k] = i;
        token[i]--;
        dfs(k + 1);
        token[i]++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> token[i];
    dfs(0);
    cout << mx << '\n' << mn;
    
    return 0;
}