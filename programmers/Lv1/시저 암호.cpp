#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (auto& c : s) {
        if (c == ' ') continue;
        c = islower(c) ? ((c - 'a') + n) % 26 + 'a' : ((c - 'A') + n) % 26 + 'A';
    }
        
    return s;
}
