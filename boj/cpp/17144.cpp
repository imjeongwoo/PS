#include <bits/stdc++.h>
using namespace std;

int r, c, t, n, result;
int g[51][51];
int cp[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};
int up[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int down[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int> > v; // 위 : v[0], 아래 : v[1]
queue<pair<pair<int, int>, int> > q; // (미세 먼지 좌표, 원래 먼지값)

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    for (int i = 1 ; i <= r; i++) {
        for (int j = 1 ; j <= c; j++) {
            cin >> g[i][j];
            if (g[i][j] == -1)
                v.push_back(make_pair(i, j));
        }
    }
    while (t != n++) {
        // 미세먼지를 큐에 넣고
        for (int i = 1 ; i <= r; i++) {
            for (int j = 1 ; j <= c; j++) {
                if (g[i][j] > 0)
                    q.push(make_pair(make_pair(i, j), g[i][j]));
            }
        }
        // 미세먼지 확산
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int origin = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx <= 0 || nx > r || ny <= 0 || ny > c || g[nx][ny] == -1) continue; 
                g[nx][ny] += origin / 5;
                g[x][y] -= origin / 5;
            }
        }
        // 공기청정기 작동
        int x = v[0].first, y = 2; // 청정기 위쪽 시작 좌표
        int tmp1 = 0, tmp2 = 0;
        int i = 0;
        while (g[x][y] != -1) {
            // cout << "좌표 : " << x  << ", " << y << '\n';
            tmp2 = g[x][y];
            g[x][y] = tmp1;
            tmp1 = tmp2;

            int nx = x + up[i][0];
            int ny = y + up[i][1];
            if (ny > c || nx < 1 || ny < 1) i++;
            x += up[i][0];
            y += up[i][1];
            
        }

        x = v[1].first, y = 2; // 청정기 아래쪽 시작 좌표 
        tmp1 = 0, tmp2 = 0, i = 0;
        while (g[x][y] != -1) {
            tmp2 = g[x][y];
            g[x][y] = tmp1;
            tmp1 = tmp2;

            int nx = x + down[i][0];
            int ny = y + down[i][1];
            if (ny > c || nx > r || ny < 1) i++;
            x += down[i][0];
            y += down[i][1];
        }
    }

    for (int i = 1 ; i <= r; i++) {
        for (int j = 1 ; j <= c; j++) {
            if (g[i][j] >0 ) result += g[i][j];
        }
    }

    cout << result;
    return 0;
}