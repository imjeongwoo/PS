#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100000];
int num[100000];

int binarySearch(int k) {
    int s = 0, e = n;
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (arr[mid] == k) return 1;
        else if (arr[mid] < k) s = mid + 1;
        else e = mid - 1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> arr[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> num[i];
    
    sort(arr, arr + n);
    for (int i = 0; i < m; i++)
        cout << binarySearch(num[i]) << '\n';

    return 0;
}