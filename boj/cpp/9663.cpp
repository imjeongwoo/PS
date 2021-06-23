#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
int vis1[28]; // 세로방향 y
int vis2[28]; // 우상단 대각 y - x + (n - 1)
int vis3[28]; // 우 하단 대각 x + y
void nQueen(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis1[i] && !vis2[cur - i + (n - 1)] && !vis3[i + cur]) {
            vis1[i] = vis2[cur - i + (n - 1)] = vis3[i + cur] = 1;
            nQueen(cur + 1);
            vis1[i] = vis2[cur - i + (n - 1)] = vis3[i + cur] = 0;
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    nQueen(0);
    cout << cnt;
    return 0;
}