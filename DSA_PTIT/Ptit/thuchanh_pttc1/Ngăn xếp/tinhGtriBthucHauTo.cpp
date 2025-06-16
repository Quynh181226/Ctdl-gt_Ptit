// Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.
// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức hậu tố exp.
// Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
// Ràng buộc:
// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
// Input
// Output
// 2
// 231*+9–
// 875*+9-
// -4
// 34

#include <bits/stdc++.h>
using namespace std;

int tinhGtri(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
}

int tinhHauTo(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int kq = tinhGtri(b, a, s[i]);
            st.push(kq);
        }
    }
    return st.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << tinhHauTo(s) << endl;
    }
    return 0;
}