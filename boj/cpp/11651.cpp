#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool func(pair<int, int> l, pair<int, int> r) {
    if (l.second == r.second) return l.first < r.first;
    return l.second < r.second;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<pair<int, int> > v;
    cin >> n;

    for (int i = 0 ; i < n; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), func);

    for (int i = 0 ; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}