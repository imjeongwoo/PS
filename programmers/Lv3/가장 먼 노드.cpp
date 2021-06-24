#include <string>
#include <vector>
#include <queue>
using namespace std;
int m[20001][20001];
int vis[20001];

void bfs(int n) {
    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    
    while(!Q.empty()) {
        int next = Q.front(); Q.pop();
        
        for (int i = 1; i <= n; i++) {
            if (m[next][i] && !vis[i]) {
                vis[i] = vis[next] + 1;
                Q.push(i);
            } 
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (auto& v : edge) m[v[0]][v[1]] = m[v[1]][v[0]] = 1;
    bfs(n);
    
    int max_dist = 0;
    for (auto& d : vis) {
        if (max_dist == d) answer++;
        else if(max_dist < d) {
            max_dist = d;
            answer = 1;
        }
    }
    return answer;
}
