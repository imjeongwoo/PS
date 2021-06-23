#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), compare);
    for(int a : v) cout << a << '\n';
    
    return 0;
}