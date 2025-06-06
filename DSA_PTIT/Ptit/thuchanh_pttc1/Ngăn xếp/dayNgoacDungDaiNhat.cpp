//
// Created by TDG on 23/05/2025.
//
// DSA07021 - DÃY NGOẶC ĐÚNG DÀI NHẤT
// Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:
// - Xâu rỗng là 1 dãy ngoặc đúng.
// - Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.
// - Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
// Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.
// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.
// Output: Với mỗi test in ra một số nguyên là độ dài dãy ngoặc đúng dài nhất tìm được.
// Input:              	Output
// 3 ((() )()()) ()(()))))	2 4 6
#include<bits/stdc++.h>
using namespace std;
main() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        stack<int> st;
        st.push(-1);
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if (s[i]=='(') {
                st.push(i);
            }else {
                st.pop();
                if (!st.empty()) {
                    cnt=max(cnt, i-st.top());
                }else{
                    st.push(i);
                }
            }
        }
        cout<<cnt<<endl;
    }
}