#include <iostream>
#include <vector>
using namespace std;

int arr[51];
int n;

void sol(int n) {
    if (n < 3) {
        if (n == 2 && arr[0] == arr[1]) {
            cout << arr[0];
            return;
        }
        cout << 'A';
        return;
    }
    int i = arr[1] - arr[0];
    int j = arr[2] - arr[1];
    if (j % i) {
        cout << 'B';
        return;
    }
    int a = j / i;
    int b = arr[1] - arr[0] * a;

    cout << arr[n - 1] * a + b;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sol(n);

    return 0;
}