#include <bits/stdc++.h>
using namespace std;

bool compare(char a, char b) {
    return (a > b);
}
// 각 자리 숫자합이 3의배수 그리고 마지막 자리가 0
void solution(string N) {
    long long sum = 0;
    bool isZero = false;

    for (int i = 0; i < N.size(); i++) {
        sum += (N[i] - '0');
        if(N[i] - '0' == 0) isZero = true;
    }
    if (sum % 3 || !isZero) cout << -1;
    else {
        sort(N.begin(), N.end(), compare);
    cout << N;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string N;
    cin >> N;
    solution(N);
    return 0;
}