#include <bits/stdc++.h>

using namespace std;

int N, K;
bool visit[100000] = {0,};
int dx[3] = {2, -1, 1};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    queue<pair<int, int> > q;

    cin >> N >> K;

    visit[N] = true;
    q.push(make_pair(N, 0));
    pair<int, int> p;
    while(!q.empty()) {

        p = q.front();
        q.pop();

        if (p.first == K) break;
        for (int i = 0; i < 3; i++) {
            int next;
            if (i) next = p.first + dx[i];
            else next = p.first * dx[i];

            if (next >= 0 && next <= 100000 && !visit[next]) {
                visit[next] = true;
                q.push(make_pair(next, p.second + 1));
            }
        }
    }
    cout << p.second;
    return 0;
}