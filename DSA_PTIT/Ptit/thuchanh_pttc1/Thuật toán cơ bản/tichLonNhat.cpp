//
// Created by TDG on 24/05/2025.
//
// Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.
// Input
// Dòng đầu tiên ghi số N (3 ≤ N ≤ 10000)
// Dòng thứ 2 ghi N số của dãy A (|Ai| ≤ 1000)
// Outpput
// Ghi ra kết quả trên một dòng
// Input
// 6
// Output
// 5 10 -2 3 5 2
// 250
#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    if (n < 3 || n > 10000) return 1;

    int a[10000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (abs(a[i]) > 1000) return 1;
    }

    sort(a, a + n);

    long long res = 1LL * a[0] * a[1] * a[n - 1];
    res = max(res, 1LL * a[n - 1] * a[n - 2] * a[n - 3]);
    res = max(res, max(1LL * a[0] * a[1], 1LL * a[n - 1] * a[n - 2]));

    cout << res;
}
