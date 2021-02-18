#include <iostream>
#include <vector>
using namespace std;

int a, b, c;

int solution(int a, int b, int c) {
    if (b == 1) return a % c;
    int val = solution(a, b/2, c);
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