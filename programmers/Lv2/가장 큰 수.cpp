#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    string string_a = to_string(a);
    string string_b = to_string(b);
    
    return string_a + string_b > string_b + string_a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    for (int n : numbers) {
        answer += to_string(n);
    }
    
    if (answer[0] == '0') return "0";
    return answer;
}
