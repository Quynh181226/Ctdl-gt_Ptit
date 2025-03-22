// Created by TDG on 22/03/2025.
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> res;

void Try(int i) {
    if (i == n) {
        // Kiểm tra có ít nhất 1 A và 1 B
        bool hasA = false, hasB = false;
        for (char c : s) {
            if (c == 'A') hasA = true;
            if (c == 'B') hasB = true;
        }
        if (hasA && hasB) res.push_back(s);
        return;
    }
    for (int j = 0; j <= 1; ++j) {
        s[i] = j + 'A';
        Try(i + 1);
    }
}

void testCase() {
    cin >> n;
    s.resize(n);
    res.clear();
    Try(0);
    sort(res.begin(), res.end()); // Sắp xếp theo thứ tự từ điển
    for (const string& x : res) {
        cout << x << "\n"; // In mỗi xâu trên một dòng
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    testCase(); // Chỉ có 1 test case
    return 0;
}
