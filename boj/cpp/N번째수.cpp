#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int s= 1, e=k;
    int result = -1;

    while(s <= e) {
        int cnt=0;
        int mid=(s+e)/2;
        for(int i=1; i<=n; i++) {
            cnt += min(mid/i, n);
        }
        if(cnt <k) s = mid + 1;
        else result = mid, e = mid-1;
    }
    cout << result << "\n";
    

    return 0;
}