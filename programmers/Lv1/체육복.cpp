#include <string>
#include <vector>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n; 
    fill(arr + 1, arr + (n + 1), 1);
    
    for (int i = 0 ; i < lost.size(); i++) {
        arr[lost[i]]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        arr[reserve[i]]++;
    }

    for (int i = 0; i < lost.size(); i++) {
        if (arr[lost[i]]) continue;
        
        if (arr[lost[i] - 1] > 1) {
            arr[lost[i] - 1]--;
            continue;
        }       
        if (arr[lost[i] + 1] > 1) {
            arr[lost[i] + 1]--;
            continue;
        } 
        answer--;
    }
    return answer;
}

