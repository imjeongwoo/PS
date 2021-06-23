#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int graph[21][21] = {0,};
int v[21][21] = {0,};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int N, sSize = 2;
int eat = 0;
queue<pair <pair<int, int> ,int> > q;

int solution();

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                q.push(make_pair(make_pair(i, j), 0));
                graph[i][j] = 0;
            }
         }
    }
    cout << solution();

    return 0;
}

int solution() {
    int dist, x, y, minDist = 999;
    pair<int, int> canEat(21, 21);
    pair<pair<int, int>, int> p;
    pair<int, int> point;
    
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        point = p.first; dist = p.second; // point : 좌표, dist = 이동거리
        x = point.first; y = point.second;
    
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= N && ny > 0 && ny <= N && !v[nx][ny] && graph[nx][ny] <= sSize) {
                int ndist = dist + 1;
                q.push(make_pair(make_pair(nx, ny), ndist));
                v[nx][ny] = 1;
                if (graph[nx][ny] > 0 && graph[nx][ny] <= 6 && graph[nx][ny] < sSize) {
                    pair<int, int> pp(nx, ny);
                    if (pp <= canEat && ndist <= minDist) {
                        canEat = pp;
                        minDist = ndist;
                    }
                }
            }
        }
    }
    if (canEat.first != 21) { // 먹을곳이 있다
        if (sSize == ++eat) {
            sSize++;
            eat = 0;
        }
        graph[canEat.first][canEat.second] = 0;
        q.push(make_pair(canEat, 0)); // 먹은 위치를 시작 위치로
        memset(v, 0, sizeof(v)); // 방문 초기화
        return minDist + solution();
    }
    return 0;
}