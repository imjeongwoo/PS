#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<string, int> mm;
    for (auto p : participant) {
        mm.insert(make_pair(p, 1));
    }
           
    for (auto s : completion) {
        if (mm.find(s) != mm.end())
            mm.erase(mm.find(s));
    }
    
    for (auto s : mm) {
        answer = s.first;
    }
    
    return answer;
}