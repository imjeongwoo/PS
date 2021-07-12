#include <string>
#include <vector>

using namespace std;

int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, 1, 0, -1};

int dx2[4] = {-1, 1, 1, -1};
int dy2[4] = {1, 1, -1, -1};

int dx3[4] = {-2, 0, 2, 0};
int dy3[4] = {0, 2, 0, -2};

bool OOB(int x, int y) {
    return x < 0 || x > 4 || y < 0 || y > 4;
}

bool check(vector<string>& room) {
    for (int x = 0; x < room.size();x++) {
        for (int y = 0; y < room[x].size(); y++) {
            if (room[x][y] == 'P') {
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx1[i], ny = y + dy1[i];
                    if (!OOB(nx, ny) && room[nx][ny] == 'P') return false;
                }  
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx2[i], ny = y + dy2[i];
                    if (!OOB(nx, ny) && (room[x][ny] != 'X' || room[nx][y] != 'X') && room[nx][ny] == 'P') return false;
                }  
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx3[i], ny = y + dy3[i];
                    if (!OOB(nx, ny) && room[x + dx3[i] / 2][y + dy3[i] / 2] != 'X' &&room[nx][ny] == 'P') return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++)
        answer.push_back(check(places[i]));
    
    return answer;
}
