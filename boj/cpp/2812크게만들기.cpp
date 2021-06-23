#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    char result[500001];
    int N, K;
    string S;

    cin >> N >> K >> S;

    int top = 0;

    for (int i = 0; i < N; i++) {
        while (K > 0 && top > 0 && S[i] > result[top - 1]) {
            top--;
            K--;
        }
        result[top++] = S[i];
    }
    result[top-K] = '\0';
    cout << result;

    return 0;
}