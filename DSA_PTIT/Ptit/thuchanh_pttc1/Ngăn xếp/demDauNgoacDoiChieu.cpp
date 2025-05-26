//
// Created by TDG on 23/05/2025.
//
// Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).
// Output:
// Với mỗi test, in ra đáp án tìm được trên một dòng.
// Input:
// 4
// ))((
// ((((
// (((())
// )(())(((
// Output
// 2
// 2
// 1
// 3
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    if (t<1||t>20) return 1;

    while (t--) {
        string s;
        getline(cin, s);
        if (s.length()>100000 || s.length()%2!=0) continue;
        stack<char> st;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    res++;
                    st.push('(');
                }
            }
        }

        res += st.size() / 2;

        cout << res << endl;
    }
    return 0;
}

