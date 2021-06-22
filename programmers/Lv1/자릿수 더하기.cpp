#include <iostream>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    for (auto c : to_string(n))
        answer += c - '0';

    return answer;
}
