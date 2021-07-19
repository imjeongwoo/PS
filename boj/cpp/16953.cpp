#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b;
int dx[2] = {1, 2};

int bfs(ll num) {
    queue<pair<ll, int> > q;
    q.push({num, 1});
    while (!q.empty()) {
        ll x = q.front().first;
        int cnt = q.front().second;
         q.pop();
        if (x == b) return cnt;
        for (int i = 0; i < 2; i++) {
            ll nx;
            if (i) nx = x * 2;
            else nx = x * 10 + 1;

            if (nx > b or nx > 1000000000) continue;
            q.push({nx, cnt + 1});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cout << bfs(a) << '\n';
    return 0;
}