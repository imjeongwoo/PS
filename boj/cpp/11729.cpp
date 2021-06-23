#include <iostream>
#include <vector>
using namespace std;

void hanoi(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n - 1);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
    hanoi(1, 3, k);

    return 0;
}