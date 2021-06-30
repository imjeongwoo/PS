#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[1000000];
int B[1000000];
int result[2000000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    int a = 0, b = 0;
    for (int i = 0; i < n + m; i++) {
        if (a == n) result[i] =  B[b++];
        else if (b == m) result[i] = A[a++];
        else if (A[a] <= B[b]) result[i] = A[a++];
        else result[i] = B[b++];
    }

    for (int idx = 0; idx < n + m; idx++) cout << result[idx] << ' ';

    return 0;
}