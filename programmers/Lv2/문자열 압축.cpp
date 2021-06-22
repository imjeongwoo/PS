#include <string>
#include <vector>

using namespace std;

string st;

int get_min_size(int window) {
    int sz = st.size();
    int cnt = 0;
    string result = "";
    string target = st.substr(0, window);

    int i;
    for (i = window; i + window <= sz; i += window) {
        if (target == st.substr(i, window)) ++cnt;
        else {
            if (cnt > 0) result += to_string(cnt + 1) + target;
            else result += target;

            target = st.substr(i, window);
            cnt = 0;
        }
    }
    if (cnt > 0) result += to_string(cnt + 1) + target;
    else result += target;
    for (int j = i; j < sz; j++) result += st[j];

    return min(sz, int(result.size()));
}

int solution(string s) {
    int answer = s.size();
    int max_window = answer / 2;
    st = s;

    for (int win_size = 1; win_size <= max_window; win_size++) {
        int current_min_size = get_min_size(win_size);
        answer = min(answer, current_min_size);
    }
    return answer;
}
