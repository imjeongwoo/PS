#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;
bool vis[201];

void dfs(int k, int n) {
    vis[k] = true;
    for (int i = 1; i <= n; i++) {
        if (v[k - 1][i - 1] && !vis[i])
            dfs(i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    v = computers;
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, n);
            answer++;
        }
    }
    return answer;
}
