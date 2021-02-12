#include <iostream>
#include <vector>
using namespace std;

long long solution(int n);

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    
    cin >> N;

    cout << solution(N);

    return 0;
}

long long solution(int n) {
    int dp[101][11] = {0};
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % int(1e9);
        }
    }

    long long result = 0;
    for (int i = 0; i <= 9; i++)
        result += dp[n][i];

    return result % int(1e9);
}