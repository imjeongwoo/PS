#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
bool f;

void dfs(string cur, vector<vector<string>> &tickets,int cnt) {
    
    answer.push_back(cur);
    if (cnt == tickets.size()){
        f = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == cur && tickets[i].size() == 2) {
            tickets[i].push_back("vis");
            dfs(tickets[i][1], tickets, cnt + 1);
            if (f) return;
            tickets[i].pop_back();
        }
    }
    answer.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, 0);
    
    return answer;
}