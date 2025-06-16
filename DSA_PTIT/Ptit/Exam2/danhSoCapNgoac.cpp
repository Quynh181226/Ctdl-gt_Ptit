//
// Created by TDG on 26/05/2025.
//
//                                      Stack
// C. Đánh số cặp ngoặc
//
// time limit per test1 second
// memory limit per test256 megabytes
//
// Cho một xâu ký tự s là một biểu thức ngoặc đúng (tức là các dấu ngoặc đơn đều đầy đủ
// mở và đóng, đảm bảo đúng thứ tự), s có thể chứa thêm cả các toán tử, toán hạng hoặc dấu cách.
// Nhiệm vụ của bạn là viết chương trình đánh số các cặp dấu ngoặc theo thứ tự xuất hiện, chỉ số
// được bắt đầu tính từ 1 .
//
// Ví dụ: với biểu thức (a + (b * c) ) + (d / e), ta có kết quả là: 1 2 2 1 3 3.
// Input
// Dòng đầu tiên chứa số bộ test t (1≤t≤104). Mỗi bộ test có dạng:
// 1 dòng duy nhất chứa xâu ký tự s là một biểu thức ngoặc đúng (2≤|s|≤2.105).
// Input đảm bảo tổng |s| của tất cả các test không vượt quá 2.105
//
// Output
// Đưa ra kết quả mỗi test trên một dòng.
//
// Example
// Input
// 2
// (a + (b * c) ) + (d/e)
// ( ( () ) ( () ) )
//
// Output
// 1 2 2 1 3 3
// 1 2 3 3 2 4 5 5 4 1

//Hint
// Vì các toán hạng có thể có nhiều chữ số, hoặc là số âm nên ta sẽ coi mỗi toán tử/toán hạng
// là một xâu ký tự. Như vậy, ta sẽ nhập vào một mảng gồm n xâu ký tự, rồi xử lý giống như bài
// ở trên Code PTIT.

// Ở đây, để kiểm tra một xâu đang duyệt đến có là "số" hay không thì ta chỉ cần kiểm tra ký tự
// cuối cùng của nó có là chữ số hay không ? Điều này sẽ giúp ta vừa kiểm tra được khi quyết định
// nhét nó vào stack cũng như là xác định biểu thức đã cho là tiền tố hay hậu tố.


#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin>>ws, s);
    stack<int> st;
    int idx=1;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') {
            st.push(idx);
            cout<<idx<<" ";
            idx++;
        }else if (s[i]==')') {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    cout<<'\n';
}

main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while (t--) {
        solve();
    }
}