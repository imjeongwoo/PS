#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, pair<int, int> > > Q;
int graph[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, h;

int solution() {
    cin >> m >> n >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) Q.push(make_pair(i, make_pair(j, k)));
            }
        }
    }
    int day = 1;
    while (!Q.empty()) {
        pair<int, pair<int, int> > point = Q.front();
        Q.pop();
        int x, y, z;
        x = point.second.first;
        y = point.second.second;
        z = point.first;
        day = graph[z][x][y];

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > h) continue;
            if (graph[nz][nx][ny]) continue;

            graph[nz][nx][ny] = day + 1;
            Q.push(make_pair(nz, make_pair(nx, ny)));
        }
    }
    return day - 1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int result = solution();
    bool isTrue = true;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (!graph[i][j][k]) {
                    isTrue = false;
                    break;
                }
            }
            if (!isTrue) continue; 
        }
        if (!isTrue) continue; 
    }

    if (!isTrue) cout << -1;
    else cout << result;

    return 0;
}