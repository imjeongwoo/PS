#include <bits/stdc++.h>

using namespace std;

void solution(string &str) {
    int alpha[26] = {0,}; // 알파벳 개수
    bool isPicked[1000000] = {false,}; // 문자 뽑기 여부
    map<char, stack<int> > remains;
    int strSize = str.size();

    for (int i = 0; i < strSize; i++) {
        alpha[str[i] - 'a']++;
        remains[str[i]].push(i);
    }

    string s = "", h = "";
    int idx = strSize; 
    for (int i = 0; i < strSize / 2; i ++) { 
        idx--;
        // 상근
        while (isPicked[idx] || alpha[str[idx] - 'a'] == 0) idx--;

        s += str[idx];
        alpha[str[idx] - 'a']--;
        isPicked[idx] = true;
        remains[str[idx]].pop(); // 가장 오른쪽에 있는거 pop

        // 희원
        char hPick;
        for (int j = 0; j < 26; j++) {
            if (alpha[j] > 0) {
                alpha[j]--;
                hPick = j + 'a';
                h += hPick;
                break;
            }
        }
        isPicked[remains[hPick].top()] = true;
        remains[hPick].pop();
    }

    if (h < s) cout << "DA\n";
    else cout << "NE\n";
    cout << h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string str;
    cin >> N >> str;
    solution(str);

    return 0;
}
// 남은것들 중에서 가장 오른쪽(뒤)에 있는 가장 빠른 알파벳
// 스택 + map 을 사용하면  같은 문자라도 뒤에 인덱스가 가장 위에 오기때문에 위의 조건을 만족 할 수 있다. 