#include <iostream>
#include <vector>
using namespace std;

void solution(int N, int *arr);

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int arr[1000];
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> arr[i];
    }
    solution(N, arr);
    return 0;
}

void solution(int N, int *arr) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        int isPrime = 1;
        int p = arr[i];
        if (p > 1) {
            int count = 0;
            for (int q = 2; q < p; q++) {
                if (p % q == 0) isPrime = 0;
            }
            if (isPrime) result++;
        }
    }
    cout << result;
}