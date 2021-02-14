#include <iostream>
#include <vector>
using namespace std;



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    for (int h = 0; h <= N; h++) {
        for (int m = 0; m <= 59; m++) {
            for (int s = 0; s <= 59; s++) {
                if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
                    count++;
            }
        }
    }
    cout << count;
    return 0;
}

/* 00시00분00초 ~ N시59분59초까지의 
모든 시각중에서 3이 하나라도 포함되는 모든 경우의수 */