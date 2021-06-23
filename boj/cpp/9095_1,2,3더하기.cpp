#include <iostream>
#include <vector>
using namespace std;

void solution(int n);

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, n;
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;
        solution(n);
    }

    return 0;
}

void solution(int n) {
    int dp[11];
    dp[1] = 1; dp[2] = 2; dp[3] = 4;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << "\n";
}