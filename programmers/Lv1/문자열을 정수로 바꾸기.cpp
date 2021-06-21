#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isNegative = s[0] == '-' ? true : false;
    string result = "";
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            result += s[i];
    answer = isNegative ? -stoi(result) : stoi(result); 
    return answer;
}
