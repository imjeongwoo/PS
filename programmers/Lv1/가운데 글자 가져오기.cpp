#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int sz = s.size();
        
    answer = s[sz / 2];
    if (sz % 2 == 0) answer = s[sz / 2 - 1] + answer;
    
    return answer;
}
