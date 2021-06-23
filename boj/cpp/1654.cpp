#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k, n, mx;
ll arr[10000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr, arr + k);

    ll s = 1, e = arr[k - 1];
    ll mid;
    while (s <= e) {
        ll sum = 0;
        mid = (s + e) / 2;
        
        for (int i = 0; i < k; i++)
            sum += arr[i] / mid;
        
        if (sum >= n) s = mid + 1;
        else e = mid - 1;
    }
    cout << e;

    return 0;
}