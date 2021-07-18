#include <bits/stdc++.h>
using namespace std;

int vis[10];
int arr[11];
int k;
vector<char> sign;
string mn = "9999999999";
string mx = "0000000000";

bool isOk(int pre, char c, int next) {
    if (c == '>') return pre > next; 
    else return pre < next;
}

void dfs(int n) {
    if (n == k) {
        string st = "";
        for (int i = 0; i <= k; i++)
            st += arr[i] + '0';
        mn = min(mn, st);
        mx = max(mx, st);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (vis[i]) continue;
        if (!isOk(arr[n], sign[n], i)) continue;
        arr[n + 1] = i;
        vis[i] = 1;
        dfs(n + 1);
        vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++) {
        char tmp; cin >> tmp;
        sign.push_back(tmp);
    }
    for (int i = 0; i <= 9; i++) {
        vis[i] = 1;
        arr[0] = i;
        dfs(0);
        vis[i] = 0;
    }
    cout << mx << '\n' << mn << '\n';
    return 0;
}