#include <string>
#include <vector>

using namespace std;
int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"THU", "FRI", "SAT", "SUN", "MON","TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    int startM = 1, startD = 1, cnt = 1;
    
    while (1) {
        if (startM == a && startD == b)
            break;
        
        startD++;
        cnt++;
    
        if (arr[startM - 1] < startD) {
            startM++;
            startD = 1;
        }
    }
    answer = day[cnt % 7];
    return answer;
}
