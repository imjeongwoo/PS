#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int arr_size = arr.size();
    
    if (arr_size == 1) {
        answer.push_back(-1);
        return answer;
    }
    
    int mn = arr[0];
    for (int i = 1; i < arr_size; i++)
        if (mn > arr[i]) mn = arr[i];

    for (int i = 0; i < arr_size; i++)
        if (arr[i] != mn) answer.push_back(arr[i]);
    
    return answer;
}
