#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> vec;
vector<string> result;
char arr[15];
bool vis[15];
bool isVowel(char& ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void dfs(int k) {
    if (k == l) {
        bool isOk = false;
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (isVowel(arr[i])) isOk = true;
            else cnt++;
        }
        if (isOk && cnt > 1) result.push_back(string(arr).substr(0, l));
        return ; 
    }

    for (int i = k; i < c; i++) {
        if (vis[i] || arr[k - 1] > vec[i]) continue;
        vis[i] = true;
        arr[k] = vec[i];
        dfs(k + 1);
        vis[i] = false;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char tmp;
        cin >> tmp; vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    dfs(0);

    for (auto& str : result) cout << str << '\n';
    return 0;
}