#include <string>
#include <vector>

using namespace std;

string arr[3] = {"1", "2", "4"};

string solution(int n) {
    string answer = "";
    
    while (n > 0) {
        n -= 1;
        answer = arr[n % 3] + answer;
        n /= 3;
    }
    return answer;
}
