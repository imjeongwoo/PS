#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string express, stringBuffer;
    cin >> express;
    istringstream ss(express);
    vector<string> split;
    while (getline(ss, stringBuffer, '-')) {
        split.push_back(stringBuffer);
    }
    int result = 0;
    if (split[0].find("+") != string::npos) {
        istringstream ss(split[0]);
        int sum = 0;
        while (getline(ss, stringBuffer, '+')) {
            result += stoi(stringBuffer);
        }
    }
    else {
        result = stoi(split[0]);
    }
    for (int i = 1; i < split.size(); i++) {
        if (split[i].find("+") != string::npos) {
            istringstream ss(split[i]);
            int sum = 0;
            while (getline(ss, stringBuffer, '+')) {
                sum += stoi(stringBuffer);
            }
            result -= sum;
        } else {
            result -= stoi(split[i]);
        }
    }
    cout << result;

    return 0;
}