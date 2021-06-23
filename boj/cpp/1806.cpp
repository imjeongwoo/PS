#include <iostream>
#include <vector>
using namespace std;

int n, s, len = 100001;
int arr[100001];

int sol() {
    int l= 0, h = 0, summary = arr[0];
    while (l <= h && h < n) {
        if (summary <= s) summary += arr[++h];
        else if (summary > s) summary -= arr[l++];

        if (summary >= s) len = min(len, (h - l + 1));
    }
    return len;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = sol();
    if (result == 100001) cout << 0;
    else cout << result;

    return 0;
}

