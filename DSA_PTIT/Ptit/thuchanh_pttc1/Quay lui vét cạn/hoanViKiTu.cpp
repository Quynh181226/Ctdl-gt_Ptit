//
// Created by TDG on 24/05/2025.
//
// Cho hai ký tự khác nhau c1 và c2 đều là chữ cái Tiếng Anh in hoa. Với điều kiện khoảng cách giữa hai ký tự này trong bảng chữ cái là không quá 10 vị trí.
// Hãy liệt kê tất cả các hoán vị của dãy ký tự ở giữa hai ký tự c1 và c2.
// Kết quả cần in ra theo thứ tự từ điển.
// Input
// Chỉ có một dòng ghi hai ký tự c1 và c2 (c1 có thể đứng trước c2 hoặc ngược lại nhưng không trùng nhau).
// Output
// Ghi ra lần lượt tất cả các hoán vị của các chữ cái giữa hai ký tự c1 và c2 theo thứ tự từ điển, mỗi ký tự ghi trên một dòng.
// Input
// E C
// Output
// CDE
// CED
// DCE
// DEC
// ECD
// EDC

#include <bits/stdc++.h>
using namespace std;

int n;
string s, conver;
bool flag[15];

void quaylui() {
    if (conver.size() == n) {
        cout << conver << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!flag[i]) {
            flag[i] = true;
            conver += s[i];
            quaylui();
            conver.pop_back();
            flag[i] = false;
        }
    }
}

main() {
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 == c2 || abs(c1 - c2) > 10) return 0;

    s = "";
    for (char ch = min(c1, c2); ch <= max(c1, c2); ++ch) {
        s += ch;
    }
    n = s.size();
    quaylui();
}

