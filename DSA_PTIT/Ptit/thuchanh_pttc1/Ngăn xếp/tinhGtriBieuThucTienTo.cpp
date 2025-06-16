//
// Created by TDG on 23/05/2025.
//
#include <bits/stdc++.h>
using namespace std;

int tinhGtri(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
}

void tinhTienTo() {
    string s; cin >> s;
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            int z = tinhGtri(x, y, s[i]);
            st.push(z);
        }
        else st.push(s[i] - '0');
    }
    cout << st.top()<<'\n';
}

main() {
    int t; cin >> t;
    while (t--) {
        tinhTienTo();
        // cout << "\n";
    }
}
