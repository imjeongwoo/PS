#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    answer = new_id;
    char lst[3] = {'-', '_', '.'};
    // 1단계
    for (int i = 0; i < answer.size(); i++)
        answer[i] = tolower(answer[i]);
    // 2단계
    for (int i = 0; i < answer.size(); i++) {
        if (!isalpha(answer[i]) && !isdigit(answer[i])) {
            int check = 0;
            for (int j = 0; j < 3; j++) {
                if (answer[i] == lst[j]) {
                    check = 1;
                    break;
                }
            }
            if (!check) answer.erase(i--, 1);
        }
    }
    // 3단계
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.') {
            for (int j = i + 1; j < answer.size(); j++) {
                if (answer[j] != '.') break;
                answer.erase(j--, 1);
            }
        }
    }
    // 4단계
    if (answer[0] == '.') answer.erase(0, 1);
    if (answer[answer.size() - 1] == '.') answer.erase(answer.size() - 1, 1);
    // 5단계
    if (answer.empty()) answer += "a";
    // 6단계
    if (answer.size() >= 16) answer.erase(15);
    if (answer[answer.size() - 1] == '.') answer.erase(answer.size() - 1, 1);
    // 7단계
    if (answer.size() <= 2)
        while (answer.size() != 3) answer += answer[answer.size() - 1];
    
    
    return answer;
}