#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1000000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    int s = 0, e = arr[n - 1];

    while (s <= e) {
        int mid = (s + e) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i ++)
            if (arr[i] - mid >= 0) sum += arr[i] - mid;
        
        if (sum >= m) s = mid + 1;
        else e = mid - 1;
    }

    cout << e;

    return 0;
}