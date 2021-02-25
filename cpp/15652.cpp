#include <iostream>
#include <vector>
using namespace std;

int arr[9];
int vis[9];
int n, m;
void sol(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if(k && arr[k-1] > i) continue;
        arr[k] = i;
        sol(k + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    sol(0);
    return 0;
}