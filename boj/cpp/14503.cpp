#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, result;
int g[50][50];
int isClear[50][50];
// {북, 동, 남, 서}
int rot[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int back[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int nxt[4] = {3, 0, 1, 2};

int sol(int x, int y, int d) {
    isClear[x][y] = 1;
    result++;

    int cnt = 0;
    while (1) {       
        int nx = x + rot[d][0]; 
        int ny = y + rot[d][1];

        // 왼쪽좌표 확인
        if (!g[nx][ny] && !isClear[nx][ny]) return sol(nx, ny, nxt[d]);
        
        d = nxt[d]; // 다음 방향으로 회전
        cnt++;
         
         if (cnt != 4) continue;
         if (g[x + back[d][0]][y + back[d][1]]) break; // 후진 못하면

         x += back[d][0];
         y += back[d][1];
         cnt = 0;
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << sol(r, c, d);
    return 0;
}