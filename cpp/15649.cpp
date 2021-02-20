#include <iostream>
#include <vector>
using namespace std;

int arr[9];
int vis[9];
int n, m;

void solution(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            arr[k] = i;
            vis[i] = 1;
            solution(k + 1);
            vis[i] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    solution(0);

    return 0;
}