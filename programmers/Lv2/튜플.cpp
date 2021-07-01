#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> m;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second >= b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string ns = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) ns += s[i];
        else {
            if (ns.empty()) continue;
            m[stoi(ns)]++;
            ns = "";
        }
    }
    
    vector<pair<int, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (auto& p : v) answer.push_back(p.first);
            
    return answer;
}
