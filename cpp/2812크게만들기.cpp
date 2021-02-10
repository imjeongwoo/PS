// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int N, K;
//     string nums;
//     deque<char> deq;

//     cin >> N >> K >> nums;


//     for (int i = 0; i < N; i++) {
//         while (K && !deq.empty() && deq.back() < nums[i]) {
//             K--;
//             deq.pop_back();
//         }

//         deq.push_back(nums[i]);
//     }
    
//     for (int i = 0; i < deq.size() - K; i++)
//         cout << deq[i];
//     cout << "\n";
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    vector<int> nums;
    deque<int> deq;

    cin >> N >> K; 
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%1d", &num);
        nums.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        while (K > 0 && !deq.empty() && deq.back() < nums[i]) {
            K--;
            deq.pop_back();
        }

        deq.push_back(nums[i]);
    }
    
    for (int i = 0; i < deq.size() - K; i++)
        cout << deq[i];
    
    return 0;
}