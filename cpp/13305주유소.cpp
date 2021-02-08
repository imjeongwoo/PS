#include <iostream>
#include <vector>
using namespace std;

long long solution(vector<long long> lengths, vector<long long> costs) {
    long long result = costs[0] * lengths[0];
    long long prev = costs[0];

    for (int i = 1; i < lengths.size(); i++) {
        if (prev > costs[i])
            prev = costs[i];  
        result += prev * lengths[i];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    vector<long long> lengths, costs;

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        long long len;
        cin >> len;
        lengths.push_back(len);
    }
    for (int i = 0; i < N; i++) {
        long long cost;
        cin >> cost;
        costs.push_back(cost);
    }
    cout << solution(lengths, costs) << "\n";

    return 0;
}
// 어이없게 long long대신 int로 해서 시간씀