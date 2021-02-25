#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
int arr[100001];

int sol() {
    int cnt = 0, low = 0, hi = n - 1;
    while (low < hi) {
        int l = arr[low], h = arr[hi];
        if (l + h == x) {
            cnt++;
            low++;
        } 
        else if (l + h < x) low++;
        else hi--;
    }
    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    cout << sol();
    return 0;
}
