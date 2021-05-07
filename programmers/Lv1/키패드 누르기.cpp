#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pair<int, int> > m;

    m[1] = {0, 0};
    m[2] = {0, 1};
    m[3] = {0, 2};
    m[4] = {1, 0};
    m[5] = {1, 1};
    m[6] = {1, 2};
    m[7] = {2, 0};
    m[8] = {2, 1};
    m[9] = {2, 2};
    m[0] = {3, 1};

    pair<int, int> left, right;
    left = {3, 0}; right = {3, 2};
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        string h;

        if (num == 1 || num == 4 || num == 7) {
            h = "L";
        }
        else if (num == 3 || num == 6 || num == 9) {
            h = "R";
        } else {
            int targetX = m[num].first;
            int targetY = m[num].second;

            if (abs(targetX - left.first) + abs(targetY - left.second) == abs(targetX - right.first) + abs(targetY - right.second) ) {
                h = hand[0] - 'a' + 'A';
            } else if (abs(targetX - left.first) + abs(targetY - left.second) < abs(targetX - right.first) + abs(targetY - right.second)) {
                h = "L";
            } else {
                h = "R";
            }
        }

        if (h == "L") {
            left = m[num];
        } else {
            right = m[num];
        }
        answer += h;
    }
    return answer;
}