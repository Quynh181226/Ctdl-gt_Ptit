//
// Created by TDG on 30/05/2025.
//
// DSA07045 - GÕ BÀN PHÍM
// Trong quá trình gõ một dòng văn bản, chúng ta thường sử dụng phím sang trái, sang phải hoặc xóa lùi (backspace). Cho một dãy ký tự mô tả các thao tác gõ phím, trong đó:
// Ký tự ‘-’ mô tả phím backspace (xóa lùi). Ký tự ở phía trước con trỏ (nếu có) sẽ bị xóa.
// Ký tự ‘<’ mô tả phím di chuyển sang trái. Con trỏ sẽ sang trái 1 ký tự nếu có thể.
// Ký tự ‘>’ mô tả phím di chuyển sang phải. Con trỏ sẽ sang phải 1 ký tự nếu có thể.
// Các ký tự khác là các chữ cái Tiếng Anh (in hoa hoặc in thường). Bàn phím để ở chế độ Insert. Tức là nếu con trỏ không ở cuối dòng thì khi chèn các ký tự sẽ đẩy các ký tự khác sang phải một vị trí.
// Hãy thử tính toán và viết ra kết quả tương ứng.
// Input
// Có một dòng không quá 106 ký tự mô tả dãy gõ bàn phím.
// Output
// Ghi ra kết quả.
// Ví dụ
// Input	Output
// <<PI<T>>Ta-	PTIT

#include <bits/stdc++.h>
using namespace std;

main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin>>s;
    stack<char> st1, st2;
    for (char c : s) {
        if (c=='-') {
            if (!st1.empty()) st1.pop();
        }else if (c=='<') {
            if (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }else if (c=='>') {
            if (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }else {
            st1.push(c);
        }
    }
    while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }
    cout<<'\n';
}