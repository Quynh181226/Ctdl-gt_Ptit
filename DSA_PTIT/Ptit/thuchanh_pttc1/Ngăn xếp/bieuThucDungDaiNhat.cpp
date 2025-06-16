//
// Created by TDG on 30/05/2025.
//
// Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’.
// Biểu thức P có thể viết đúng hoặc không đúng.Nhiệm vụ của bạn là tìm
// tổng độ dài lớn nhất của các biểu thức con viết đúng trong P (các
// biểu thức đúng không nhất thiết phải liên tiếp nhau).
// Chú ý: Độ dài của biểu thức đúng ngắn nhất là 2.
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T (không quá 100)
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test.
// Mỗi bộ test là một biểu thức P được viết trên một
// dòng (độ dài của P không quá 100).
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:
// Input
// 4
// (()(
// ()()((
// ((()()())))
// ()(())(
// Output
// 2
// 4
// 10
// 6

#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    stack<char> st;
    int cnt=0;
    for (char c: s) {
        if (c=='('){
            st.push(c);
        }else if (c==')' && !st.empty()) {
            st.pop();
            cnt+=2;
        }
    }
    return cnt;
}
main() {
    int t; cin>>t;
    while (t--) {
        string s; cin>>s;
        cout<<solve(s)<<'\n';
    }
}