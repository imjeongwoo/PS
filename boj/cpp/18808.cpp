#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
int sticker[10][10];
int note[40][40];

void rotate() {
    int tmp[10][10];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) 
            tmp[i][j] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++) 
            sticker[i][j] = tmp[r - 1- j][i];

    swap(r, c);
}

bool isOk(int x, int y) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (note[x + i][y + j] == 1 && sticker[i][j] == 1)
                return false;
    return true;
}

void paste(int x, int y) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sticker[i][j] == 1)
                note[x + i][y + j] = 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];

        int rotation = 4;
        while (rotation--) {
            bool flag = false;
            for (int x = 0; x <= n - r; x++) {
                for (int y = 0; y <= m - c; y++) {
                    if (isOk(x, y)) {
                        paste(x, y);
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            rotate();
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += note[i][j];
    cout << cnt;
    return 0;
}