#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int result[1000000];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(make_pair(num, i));
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        int idx = v[i].second;
        int num = v[i].first;

        int preIdx = v[i - 1].second;
        int pre = v[i - 1].first;

        if (pre < num)
            result[idx] = result[preIdx] + 1;
        else
            result[idx] = result[preIdx];
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';

    return 0;
}