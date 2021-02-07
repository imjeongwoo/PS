#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, sum = 0;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++) {
        v[i] = v[i-1] + v[i];
    }
    cout << accumulate(v.begin(), v.end(), 0);
    // numeric 헤더 함수 accumulate
    // accumulate(first, last, inital value)

    return 0;
}
