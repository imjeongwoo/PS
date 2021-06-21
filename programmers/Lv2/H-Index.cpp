#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int sz = citations.size();
    sort(citations.begin(), citations.end(), compare);
    int l = min(sz, citations[0]);

    for (int i = l; i >= 0; i--) {
        int cnt = 0;
        for (int n : citations) {
            if (n >= i) cnt++;
        }
        if (cnt >= i) {
            answer = i;
            break;
        }
    }
    return answer;
}
