#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    int arr[300] = {0,};
    int dp[300] = {0,};
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[2] +arr[1], arr[2] + arr[0]);
    for (int i = 3; i < n; i++) {
        dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
    }
    cout << dp[n -1];
    return 0;
}