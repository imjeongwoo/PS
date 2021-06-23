#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

int solution(string d) {
    int answer = 0;
    vector<int> v;

    string cur = "";
    for (int i = 0; i < d.size(); i++) {
        int cur_score = 0;
        if (isdigit(d[i])) cur += d[i];
        else if (isalpha(d[i])) {
            switch (d[i]) {
                case 'S':
                    cur_score = stoi(cur);
                    break;
                case 'D':
                    cur_score = pow(stoi(cur), 2);
                    break;
                case 'T':
                    cur_score = pow(stoi(cur), 3);
                    break;
            }
            if (d[i + 1] == '*') {
                if (!v.empty()) v[v.size() - 1] *= 2;
                cur_score *= 2;
                i++;
            }
            else if (d[i + 1] == '#') {
                cur_score *= -1;
                i++;
            }            
            v.push_back(cur_score);
            cur = "";
        }
    }

    for (auto& n : v) answer += n;
    return answer;
}
