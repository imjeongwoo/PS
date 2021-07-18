#include <bits/stdc++.h>
using namespace std;

int vis[8];
int nums[8];
int arr[8];
int n, mx;

void dfs(int k) {
    if (k == n) {
        int s = 0;
        for (int i = 0; i < n - 1; i++)
            s += abs(arr[i] - arr[i + 1]);
        mx = max(mx, s);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        arr[k] = nums[i];
        dfs(k + 1);
        vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    dfs(0);
    cout << mx;
    
    return 0;
}