#include <bits/stdc++.h>
using namespace std;

int w, h;
int M[50][50];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

void bfs(int a, int b) {
    queue<pair<int, int> > Q;

    M[a][b] = 0;
    Q.push(make_pair(a, b));

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > w || ny < 0 || ny > h) continue;
            if (!M[nx][ny]) continue;
            
            M[nx][ny] = 0;
            Q.push(make_pair(nx, ny));
        }
    }
}

//0 이면 못감
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while (true) {
        cin >> w >> h;
        if (!w && !h) break;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> M[i][j];
        
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

        for (int i = 0; i < h; i++)
            fill(M[i], M[i] + w, 0);
    }
    return 0;
}