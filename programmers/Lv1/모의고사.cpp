#include <string>
#include <vector>

using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int check[4];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for (int i = 0; i < answers.size(); i++) {
        if (a[i % 5] == answers[i]) check[1]++;
        if (b[i % 8] == answers[i]) check[2]++;
        if (c[i % 10] == answers[i]) check[3]++;
    }
    
    int mx = max(check[1], max(check[2], check[3]));
    
    if (mx == check[1]) answer.push_back(1);
    if (mx == check[2]) answer.push_back(2);
    if (mx == check[3]) answer.push_back(3);
    
    return answer;
}