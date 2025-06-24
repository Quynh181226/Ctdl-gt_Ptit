//
// Created by TDG on 24/05/2025.
//
// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.
// Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.
// Các dãy con được liệt kê lần lượt theo thứ tự từ điển.
// Input
// Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
// Dòng đầu ghi hai số N và K (2 < K < N <15)
// Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
// Output
// Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng.
// Input
// 1
// 4 3
// 3 2 5 4
// Output
// 2 3 4
// 2 3 5
// 2 4 5
// 3 4 5

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100], b[100];

void quaylui(int i) {
    for(int j = a[i - 1] + 1; j <= n - k + i - 1; j++) {
        a[i] = j;
        if(i == k) {
            for(int idx = 1; idx <= k; idx++) {
                cout << b[a[idx]] << " ";
            }
            cout << "\n";
        }
        else {
            quaylui(i + 1);
        }
    }
}

main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(b, b + n);
        a[0] = -1;
        quaylui(1);
    }
}