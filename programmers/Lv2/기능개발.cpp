#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    
    for (int i = 0; i < progresses.size(); i++) {
        int day = (100 - progresses[i]) % speeds[i] ? (100 - progresses[i]) / speeds[i] + 1 : (100 - progresses[i]) / speeds[i];
        Q.push(day);
    }
    
    while (!Q.empty()) {
        int mx = Q.front(); Q.pop();
        int cnt = 1;       
        while (!Q.empty() && Q.front() <= mx) {
            Q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}
