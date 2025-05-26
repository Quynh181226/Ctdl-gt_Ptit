// Created by TDG on 22/03/2025.
// Xâu AB là dãy ký tự chỉ bao gồm hai chữ cái A và B.
// Hãy liệt kê các xâu AB độ dài N thỏa mãn cả 2 điều kiện:
// Có ít nhất 1 ký tự A
// Có ít nhất 1 ký tự B
// Input
// Chỉ có 1 dòng ghi số N (2 < N < 15).
// Output
// Ghi ra lần lượt các xâu AB thỏa mãn điều kiện theo thứ tự từ điển.
// Ví dụ
// In-Out:
// 4 - AAAB

//     AABA

//     AABB

//     ABAA

//     ABAB

//     ABBA

//     ABBB

//     BAAA

//     BAAB

//     BABA

//     BABB

//     BBAA

//     BBAB

//     BBBA

//     BBBB
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> res;

void Try(int i) {
    if (i == n) {
        bool hasA = false, hasB = false;
        for (char c : s) {
            if (c == 'A') hasA = true;
            if (c == 'B') hasB = true;
        }
        if (hasA && hasB) res.push_back(s);
        return;
    }
    for (int j = 0; j <= 1; j++) {
        s[i] = j + 'A';
        Try(i + 1);
    }
}

int main() {
    cin >> n;
    s.resize(n);
    Try(0);
    sort(res.begin(), res.end());
    for (string r : res) cout << r << endl;
    return 0;
}
