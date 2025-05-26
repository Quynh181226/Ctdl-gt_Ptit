//
// Created by TDG on 24/05/2025.
//
// Có N người xếp hàng với N cái tên phân biệt. Người ta muốn xếp một người duy nhất luôn đứng ở cuối hàng. Hãy liệt kê tất cả các cách xếp hàng thoả mãn theo thứ tự từ điển.
// Input
// Dòng đầu ghi số N (1 < N < 10) là số người xếp hàng
// Dòng 2 ghi N cái tên khác nhau từng đôi một, mỗi cái tên là một dãy ký tự độ dài không quá 30 và không có khoảng trống.
// Dòng 3 ghi tên người luôn đứng cuối hàng. Dữ liệu đảm bảo tên của người đứng cuối luôn có trong danh sách ở dòng 2.
// Output
// Ghi ra danh sách tất cả các cách xếp hàng theo thứ tự từ điển tăng dần.
// Ví dụ
// Input
// 4
// DONG TAY NAM BAC
// NAM
// Output
// BAC DONG TAY NAM
// BAC TAY DONG NAM
// DONG BAC TAY NAM
// DONG TAY BAC NAM
// TAY BAC DONG NAM
// TAY DONG BAC NAM

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> names;
vector<string> perm;
vector<bool> flag;
string last;

void quaylui(int pos) {
    if (pos == n - 1) {
        for (int i = 0; i < n - 1; i++) {
            cout << perm[i] << " ";
        }
        cout << last << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (!flag[i]) {
            flag[i] = true;
            perm[pos] = names[i];
            quaylui(pos + 1);
            flag[i] = false;
        }
    }
}

main() {
    cin >> n;
    if (n <= 1 || n >= 10) return 1;

    vector<string> all(n);
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
    cin >> last;

    for (int i = 0; i < n; i++) {
        if (all[i] != last) {
            names.push_back(all[i]);
        }
    }

    if (names.size() != n - 1) return 1;

    sort(names.begin(), names.end());

    perm.resize(n - 1);
    flag.assign(n - 1, false);
    quaylui(0);
}