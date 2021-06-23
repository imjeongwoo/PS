#include <iostream>
#include <vector>
using namespace std;

int z(int n,int r, int c) {
    if (n == 0) return 0;

    int h = 1 << (n-1);
    if (r < h && c < h) return z(n - 1, r, c);
    if (r < h && c >= h) return z(n - 1, r, c - h) + h * h;
    if (r >= h && c < h) return z(n - 1, r - h, c) + 2 * h * h;
    return z(n - 1, r - h, r - h) + 3 * h * h;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, r, c;
    cin >> n >> r >> c;
    cout << z(n, r, c);

    return 0;
}

// 왼 오 왼 오
// 1 << n 에서              >> 1
