#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int tomato[1000][1000] = {0};

int solution(queue<pair<int, int> > &q, int m, int n) {
    int day = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first; int x = p.second;
        for (int i = 0; i < 4; i++){
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && tomato[newY][newX] == 0) {
                day = tomato[y][x];
                tomato[newY][newX] = day + 1;
                q.push(make_pair(newY, newX));
            }
        }
    }
    return day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n, result;
    queue<pair<int, int> > q;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push(make_pair(i, j));
        }
    } 
    result = solution(q, m, n);
    
    bool isTrue = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0)
                isTrue = true;
        }
    } 
    if (isTrue) cout << 0;
    else cout << result;
    
    return 0;
}