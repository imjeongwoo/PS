#include <bits/stdc++.h>
using namespace std;

int arr[300][300];
int tmp[300][300];
int n, m, r;

void rotate_arr(int x, int y, int n, int m) {
    
    int tmp = arr[x][y];

    for (int i = y; i < m - 1; i++)
        arr[x][i] = arr[x][i + 1];
    for (int i = x; i < n - 1; i++)
        arr[i][m - 1] = arr[i + 1][m - 1];
    for (int i = m - 1; i > y; i--)
        arr[n - 1][i] = arr[n - 1][i - 1];
    for (int i = n - 1; i > x; i--)
        arr[i][y] = arr[i - 1][y];
    
    arr[x + 1][y] = tmp;

    if (x + 1 < n - 1 && y + 1 < m - 1) rotate_arr(x + 1, y + 1, n - 1, m - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    
    while (r--)
        rotate_arr(0, 0, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}