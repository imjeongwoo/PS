#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> &v) {

    sort(v.begin(), v.end());

    int i, j, sum = 0;

    for (i = 0; i < v.size(); i += 2) {
        if (v[i] < 1 && v[i + 1] < 1) sum += v[i] * v[i + 1];
        else break;
    }

    for (j = v.size() - 1; j >= i; j -= 2) {
        if (v[j] > 1 && v[j - 1] > 1) sum += v[j] * v[j - 1];
        else break;
    }

    for (; i <= j; i++) sum += v[i];
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, num;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    int result = solution(v);
    cout << result;
    return 0;
}