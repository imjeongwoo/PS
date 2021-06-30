#include <bits/stdc++.h>

using namespace std;
int g[20][20];
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, 1, -1};

bool solution(int x, int y, int idx) {
    int cnt = 1;

    int nx = x + dx[idx], ny = y + dy[idx];
    while (nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19 && g[nx][ny] == g[x][y]) {
        cnt++;
        nx += dx[idx];
        ny += dy[idx];
    }
 
    if (cnt == 5) {
        if (x - dx[idx] >= 1 && x - dx[idx] <= 19 && y - dy[idx] >= 1 && y - dy[idx] <= 19)
            if (g[x - dx[idx]][y - dy[idx]] == g[x][y])
                return false;
        return true;
    }
    
    return false;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 20; j++)
            cin >> g[i][j];

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (g[i][j]) {
                for (int k = 0; k < 4; k++) {
                    if (solution(i, j, k)) {
                        if (k == 3) cout << g[i][j] << '\n' << i + 4 * dx[k] << ' ' << j + 4 * dy[k];
                        else cout << g[i][j] << '\n' << i << ' ' << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0;       
    return 0;
}