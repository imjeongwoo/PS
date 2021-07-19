#include <bits/stdc++.h>
using namespace std;

int cell[1025][1025];
int n, m;

int solution(int x1, int y1, int x2, int y2) {
    int result = 0;
    for (int x = x1; x <= x2; x++)
        result += cell[x][y2] - cell[x][y1 - 1];
    return result;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= n; j++ ) {
            cin >> cell[i][j];
            cell[i][j] += cell[i][j - 1];
        }
    }
    for (int i = 0; i < m; i ++) {
        int x1, x2 ,y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solution(x1, y1, x2, y2) << '\n';
    }
    return 0;
}