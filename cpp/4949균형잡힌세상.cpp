#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string str;

    while (getline(cin, str) && str != ".") {
        stack<char> S;
        for (auto c : str) {
            if (c == '(' || c == '[') S.push(c);
            else if (c == ')') {
                if (!S.empty() && S.top() == '(') S.pop();
                else break;
            }
            else if (c == ']') {
                if (!S.empty() && S.top() == '[') S.pop();
                else break;
            }
        }
        if (S.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    cout << "yes";
    return 0;
}