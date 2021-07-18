#include <bits/stdc++.h>
using namespace std;

int n, k;
int gold[1001];
int silver[1001];
int bronze[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1 ; i <= n; i++) {
        int num;
        cin >> num;
        cin >> gold[num] >> silver[num] >> bronze[num];
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (gold[k] < gold[i]) answer++;
        else if (gold[k] == gold[i]) {
            if (silver[k] < silver[i]) answer++;
            else if (silver[k] == silver[i] && bronze[k] < bronze[i]) answer++;
        }
    }
    cout << answer + 1;
    return 0;
}