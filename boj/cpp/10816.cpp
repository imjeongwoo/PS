#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[500000];
map<int, int> mapp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        mapp[k]++;
    }    
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    
    for (int i = 0; i < m; i++)
        cout << mapp[arr[i]] << ' ';
    
    return 0;
}