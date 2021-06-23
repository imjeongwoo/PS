#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<char, char> > m;

void preorder(char root) {
    if (root == '.') return;
    cout << root;
    preorder(m[root].first);
    preorder(m[root].second);
}

void inorder(char root) {
    if (root == '.') return;
    inorder(m[root].first);
    cout << root;
    inorder(m[root].second);
}

void postorder(char root) {
    if (root == '.') return;
    postorder(m[root].first);
    postorder(m[root].second);
    cout << root;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;

        m[p] = make_pair(l, r);
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}