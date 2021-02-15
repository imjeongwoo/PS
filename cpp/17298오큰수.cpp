#include <bits/stdc++.h>
using namespace std;

int N, top = 0;
int arr[1000001] = {0,};
int result[1000001];
int stk[1000001] = {0,};
int indexStack[1000001] = {0,};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(result, -1, sizeof(result));
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {

        while (top > 0 && stk[top] < arr[i]) {
            int idx = indexStack[top];
            result[idx] = arr[i];
            top--;
        }

        stk[++top] = arr[i];
        indexStack[top] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    return 0;
}