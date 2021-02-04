#include <iostream>

using namespace std;

long long dp[41] = {0,};

long long fibo(int n) {
    if (n == 0) return dp[n] = 0;
    if (n ==1 || n == 2) return dp[n] = 1;
    if (dp[n]) return dp[n];

    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int T, N;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N) {
            fibo(N);
            cout << dp[N-1] << " " << dp[N] << "\n";
        } else { cout << "1 0\n"; }  
    }
    return 0;
}
