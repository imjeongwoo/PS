#include <bits/stdc++.h>
using namespace std;

int k, result;
int gear[5][8];
int rot[100][2];
int vis[5];

void rotateGear(int num, int dir) {
    int  tmp, tmp2;
    if (dir == 1) { // 시계방향
        tmp = gear[num][7]; // 톱니의 마지막 극
        for (int i = 0; i <= 7; i++) {
            tmp2 = gear[num][i];
            gear[num][i] = tmp;
            tmp = tmp2;
        }
        return;
    }
    // 반시계 방향
    tmp = gear[num][0];
    for (int i = 7; i >= 0; i--) {
        tmp2 = gear[num][i]; // 톱니의 12시 방향 극
        gear[num][i] = tmp;
        tmp = tmp2;
    }
}

void dfs(int cur, int dir) {
    vis[cur] = 1;
    if (cur - 1 > 0 && cur - 1 <= 4 && !vis[cur - 1] && gear[cur - 1][2] != gear[cur][6])
        dfs(cur - 1, -dir);
    if (cur + 1 > 0 && cur + 1 <= 4 && !vis[cur + 1] && gear[cur + 1][6] != gear[cur][2])
        dfs(cur + 1, -dir);
    rotateGear(cur, dir);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 1; i <= 4; i++) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
            gear[i][j] = s[j] - '0';
    }

    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> rot[i][0] >> rot[i][1];
    
    for (int i = 0; i < k; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(rot[i][0], rot[i][1]);
    }

    if (gear[1][0]) result += 1;
    if (gear[2][0]) result += 2;
    if (gear[3][0]) result += 4;
    if (gear[4][0]) result += 8;
    cout << result;
    return 0;
}