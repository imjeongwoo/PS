#include <string>
#include <vector>

using namespace std;
int cnt, t;
int nums[20];
vector<int> v;
void dfs(int k) {
    if (k == v.size()) {
        int tn = 0;
        for (int i = 0; i < v.size(); i++) tn += nums[i];
        if (tn == t) cnt++;
        return;
    }
    
    nums[k] = v[k];
    dfs(k + 1);
    nums[k] = -v[k];
    dfs(k + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    v = numbers;
    t = target;
    dfs(0);
    return cnt;
}
