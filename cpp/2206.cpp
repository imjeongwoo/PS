#include <iostream>
#include <queue>
#define MAXSIZE 1000
#define X first
#define Y second
using namespace std;

int n, m;
int graph[MAXSIZE][MAXSIZE];
int vis[MAXSIZE][MAXSIZE][2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int bfs();
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    printf("%d", bfs());

    return 0;
}

int bfs() {
    queue<pair<pair<int, int>, int> > Q;
    Q.push(make_pair(make_pair(0, 0), 0));
    vis[0][0][0] = 1;

    while (!Q.empty()) {
        auto point = Q.front().first;
        int cnt = Q.front().second; Q.pop();
        if (point.X == n - 1 && point.Y == m - 1) return vis[point.X][point.Y][cnt];

        for (int i = 0; i < 4; i++) {
            int nx = point.X + dx[i];
            int ny = point.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny][cnt] != 0) continue;

            if (graph[nx][ny] == 1 && cnt == 0) {
                vis[nx][ny][cnt + 1] = vis[point.X][point.Y][cnt] + 1;
                Q.push(make_pair(make_pair(nx, ny), cnt + 1));
            }

            if (graph[nx][ny] == 0) {
                vis[nx][ny][cnt] = vis[point.X][point.Y][cnt] + 1;
                Q.push(make_pair(make_pair(nx, ny), cnt));
            }
        }
    }
    return -1;
}