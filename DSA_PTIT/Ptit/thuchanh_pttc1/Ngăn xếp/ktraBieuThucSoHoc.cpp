//
// Created by TDG on 23/05/2025.
//
// Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
// Input :
// 3
// ((a+b))
// (a + (b)/c)
// (a + b*(c-d))
// Output :
// Yes
// Yes
// No

#include <bits/stdc++.h>
using namespace std;

bool Solve(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty()) return true;
            if (st.top() == '(') return true;

            bool check = false;
            while (!st.empty() && st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    check = true;
                }
                st.pop();
            }
            if (!st.empty()) st.pop();

            if (!check) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    if (t < 1 || t > 100) return 1;
    while (t--) {
        string s;
        getline(cin, s);
        if (s.length() < 2 || s.length() > 20) continue;
        if (Solve(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

