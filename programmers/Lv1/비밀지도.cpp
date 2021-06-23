#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> result;
    for (int i = 0 ; i < n; i++)
        result.push_back(int(arr1[i] | arr2[i]));

    for (auto& r : result) {
        stack<int> s;
        while (r / 2) {
            s.push(r % 2);
            r /= 2;
        }
        s.push(1);
        while (s.size() < n) s.push(0);

        string bin_string = "";
        while (!s.empty()) {
            int num = s.top(); s.pop();
            bin_string += num ? "#" : " ";
        }
        answer.push_back(bin_string);
    }
    return answer;
}
