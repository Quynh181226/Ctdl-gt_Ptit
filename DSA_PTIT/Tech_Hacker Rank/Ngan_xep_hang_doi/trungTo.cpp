//
// Created by TDG on 27/05/2025.
//#include <iostream>
#include<iostream>
#include <stack>
using namespace std;

void solve(string s) {
    stack<string> st;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(isalpha(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    cout << st.top() << endl;
}

int main() {
    string s = "*+AB-CD";  // prefix
    solve(s);              // output: ((A+B)*(C-D))
    return 0;
}
