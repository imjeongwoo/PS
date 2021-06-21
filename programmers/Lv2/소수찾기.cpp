#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool vis[10000000];
bool vis_idx[8];
char num[7];
vector<char> v;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int k, int n, int& answer) {
    if (k == n) {
        string number = "";
        for(int i = 0; i < n; i++) {
            if (number == "" && num[i] == 0) continue;
            number += num[i];
        }
        int int_number = stoi(number);
        if (!vis[int_number]) {
            if (isPrime(int_number) && int_number > 1) answer++;
            vis[int_number] = true;
        }  
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (vis_idx[i]) continue;
        vis_idx[i] = true;
        num[k] = v[i];
        dfs(k + 1, n, answer);
        vis_idx[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(numbers[i]);
    }

    for (int i = 1; i <= v.size(); i++) {
        dfs(0, i, answer);
    }

    return answer;
}
