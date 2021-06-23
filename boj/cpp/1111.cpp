#include <iostream>
#include <vector>
using namespace std;

int arr[51];
int n;

void sol(int n) {
    int a, b;

    if (n < 3) {
        if (n == 2 && arr[0] == arr[1]) {
            cout << arr[0];
            return;
        }
        cout << 'A';
        return;
    }
    if (arr[0] == arr[1]) {
        if (arr[1] != arr[2]) {
            cout << 'B';
            return;
        }
        a = 1;
        b = 0;
    } else {
        int i = arr[1] - arr[0];
        int j = arr[2] - arr[1];
         if (j % i) {
             cout << 'B';
             return;
        }
        a = j / i;
        b = arr[1] - arr[0] * a;
    }
    
    bool isTrue = true;
    for (int i = 3; i < n; i++) {
        if (arr[i] != arr[i - 1] * a + b) {
            isTrue = false;
            break;
        }
    }

    if (isTrue) cout << arr[n - 1] * a + b;
    else cout << 'B';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sol(n);

    return 0;
}