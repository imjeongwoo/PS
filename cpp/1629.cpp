#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll a, b, c;

ll solution(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll val = solution(a, b/2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> c;
    cout << solution(a, b, c);

    return 0;
}