#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cut[100];

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto c : commands) {
        int i = c[0] - 1, j = c[1], k = c[2] - 1;
        int cutSize = j - i, cutIdx = 0;

        for (int a = i; a <= j; a++)
            cut[cutIdx++] = array[a];
        sort(cut, cut + cutSize);
        answer.push_back(cut[k]);
    }   
    return answer;
}