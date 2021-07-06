#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (result.back() == s[i]) result.pop_back();
        else result += s[i];
    }
    return result == "" ? 1 : 0;
}
