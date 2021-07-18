#include <string>
#include <vector>

using namespace std;
string tar;
int vis[50];
vector<string> w;
int mn = 987654321;

void dfs(string st, int depth) {
    if (st == tar) {
        mn = min(mn, depth);
        return;
    }

    for (int i = 0; i < w.size(); i++) {
        if (vis[i]) continue;
        int cnt = 0;
        for (int j = 0; j < st.size() && cnt < 2; j++)
            if (st[j] != w[i][j]) cnt++;
        if (cnt != 1) continue;
        vis[i] = 1;
        dfs(w[i], depth + 1);
        vis[i] = 0;
    }
}        
int solution(string begin, string target, vector<string> words) {
    w = words;
    tar = target;
    dfs(begin, 0);
    return mn == 987654321 ? 0 : mn;
}
