#include <iostream>
#include <queue>
#include <utility>
using namespace  std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int graph[100][100] = {0,};
int cnt[100][100] = {0,};
queue< pair<int, int> > q;

pair<int, int> qpop(queue< pair<int, int> > &que) {
    pair<int, int> result = que.front();
    que.pop();
    return result;
}

void bfs(int n, int m) {
    q.push(make_pair(0, 0));
    cnt[0][0] = 1;
    graph[0][0] = 0;
    while(!q.empty()) {
        pair<int, int> p = qpop(q);
        int x = p.second; int y = p.first;
        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(0 <= newX && newX < m && 0 <= newY && newY < n && graph[newY][newX]) {
                cnt[newY][newX] = cnt[y][x]+1;
                graph[newY][newX] = 0;
                q.push(make_pair(newY, newX));
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &graph[i][j]);
    bfs(n, m);
    printf("%d\n", cnt[n-1][m-1]);
    return 0;
}
