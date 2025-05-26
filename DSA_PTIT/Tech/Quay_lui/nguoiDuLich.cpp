//
// Created by TDG on 22/05/2025.
//
// DSA02027 - NGƯỜI DU LỊCH
// Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.
//
// Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
//
// Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.
//
// Kết quả: Chi phí mà người đó phải bỏ ra.
//
// Ví dụ:
//
// INPUT                                        	OUTPUT
// 4 0 20 35 10 20 0 90 50 35 90 0 12 10 50 12 0	117

// https://code.ptit.edu.vn/student/question/DSA02027
// NGƯỜI DU LỊCH

#include <bits/stdc++.h>
using namespace std;

int n, minKc, ans;
int a[20][20], vs[20];

void Try(int ind, int cou, int val) {
    //! nếu chi phí hiện tại + chi phí tối thiểu để đi (n - k + 1) tp còn lại >= ans thì k cần đi nữa vì chắc chắn k tối ưu
    if (val + minKc * (n - cou + 1) >= ans) return;
    if (cou == n) {
        val += a[ind][1];
        ans = min(ans, val);
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (vs[i] == 0) {
            vs[i] = 1;
            Try(i, cou + 1, val + a[ind][i]);
            vs[i] = 0;
        }
    }
}

void testCase() {
    minKc = ans = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            minKc = min(minKc, a[i][j]);
        }
    }
    vs[1] = 1;
    Try(1, 1, 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 1;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}





#include <iostream>

using namespace std;

int a[20][20];
int n;
bool used[20];
int kq;

void quayLui(int i, int cur, int sum) {
    for(int j = 1; j < n; j++) {
        if(!used[j] && sum + a[cur][j] < kq) {
            used[j] = true;
            sum += a[cur][j];
            if(i == n - 2) {
                kq = min(kq, sum + a[j][0]);
            }
            else quayLui(i + 1, j, sum);
            sum -= a[cur][j];
            used[j] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        used[i] = false;
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    kq = 1e9;
    quayLui(0, 0, 0);
    cout << kq;
    return 0;
}