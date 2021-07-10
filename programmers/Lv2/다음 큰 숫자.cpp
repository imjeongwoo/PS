#include <string>
#include <vector>

using namespace std;

int countOne(int n) {
    int cnt =0;
    while (n > 0) {
        if (n % 2) ++cnt;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int nCount = countOne(n);

    for (int i = n + 1; i < 987654321; i++) {
        if (nCount == countOne(i)) return i;
    }
}
