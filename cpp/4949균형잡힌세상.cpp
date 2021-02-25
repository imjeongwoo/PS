#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string str;
    

    while (true) {
        bool isTrue = true;
        getline(cin, str);
        if (str == ".") break;
        stack<char> S;
        for (auto c : str) {
            if (c == '(' || c == '[') S.push(c);
            else if (c == ')') {
                if (!S.empty() && S.top() == '(') S.pop();
                else {
                    isTrue = false;
                    break;
                }
            }
            else if (c == ']') {
                if (!S.empty() && S.top() == '[') S.pop();
                else {
                    isTrue = false;
                    break;
                }
            }
        }
        if (!S.empty()) isTrue = false;
        if (isTrue) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}