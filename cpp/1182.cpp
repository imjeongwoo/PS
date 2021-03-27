#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int num[20];
int vis[20];

void dfs(int cur, int result) {
    if (cur == n) {
        if (result == s) cnt++;
        return;
    }
    dfs(cur + 1, result);
    dfs(cur + 1, result + num[cur]);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    dfs(0, 0);

    if  (s == 0) cnt--;
    cout << cnt;

    return 0;
}