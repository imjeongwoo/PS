#include <bits/stdc++.h>
#define MAX 2<<7

using namespace std;
int g[MAX][MAX];
int cnt[2];
int n;

void cutPaper(int x, int y, int len) {
    if (len == 1) {
        cnt[g[x][y]]++;
        return;
    }

    bool flag = true;
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (g[x][y] != g[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag == false) break;
    }

    if (flag) {
        cnt[g[x][y]]++;
        return;
    }
    else {
        cutPaper(x, y ,len / 2);
        cutPaper(x, y + len / 2 ,len / 2);
        cutPaper(x + len / 2, y ,len / 2);
        cutPaper(x + len / 2, y + len / 2 ,len / 2);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    cutPaper(1, 1, n);
    cout << cnt[0] << '\n' << cnt[1] << '\n';

    return 0;
}