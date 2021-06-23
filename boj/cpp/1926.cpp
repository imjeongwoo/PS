#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int graph[500][500];
int n, m, maxWidth, cnt;
void solution(int a, int b) {
    int curWidth = 1;
    queue<pair<int, int> > Q;
    graph[a][b] = 0;
    Q.push(make_pair(a, b));

    while (!Q.empty()) {
        auto point = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = point.X + dx[i];
            int ny = point.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (graph[nx][ny] == 0) continue;

            graph[nx][ny] = 0;
            Q.push(make_pair(nx, ny));
            curWidth++;
        }
    }
    maxWidth = max(curWidth, maxWidth);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) {
                solution(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << maxWidth;
    return 0;
}



 