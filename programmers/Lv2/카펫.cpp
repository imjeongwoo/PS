#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sz = brown + yellow;
    for (int n = 3; n < sz; n++) {
        if (sz % n) continue;
        int m = sz / n;
        if (m >= n && (m - 2) * (n - 2) == yellow) {
            answer.push_back(m);
            answer.push_back(n);
        }
    }
    return answer;
}
