#include <string>

using namespace std;

string solution(string s) {
    bool isEven = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isEven = true;
            continue;
        }

        if (!isEven && s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        else if (isEven && s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
        isEven = !isEven;
    }
    return s;
}
