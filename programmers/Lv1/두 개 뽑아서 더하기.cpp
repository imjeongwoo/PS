#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int vis[201];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (!vis[numbers[i] + numbers[j]])
                vis[numbers[i] + numbers[j]] = 1;
        }
    }

    for (int i = 0; i < 201; i++)
        if (vis[i]) answer.push_back(i);


    return answer;
}