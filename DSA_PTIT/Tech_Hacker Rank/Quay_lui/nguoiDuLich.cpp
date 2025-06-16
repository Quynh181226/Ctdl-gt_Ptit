//
// Created by TDG on 22/05/2025.
//
// DSA02027 - NGƯỜI DU LỊCH
// Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng,
// mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi
// phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.
//
// Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi
// thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
//
// Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng
// chứa n số nguyên thể hiện cho mảng 2 chiều C.
//
// Kết quả: Chi phí mà người đó phải bỏ ra.
//
// Ví dụ:
//
// INPUT                                        	OUTPUT
// 4 0 20 35 10 20 0 90 50 35 90 0 12 10 50 12 0	117

//Hint
// Nhập ma trận chi phí và khởi tạo used, kq.
// Bắt đầu từ thành phố 0, dùng quay lui để thử mọi đường đi qua n-1 thành phố còn lại.
// Khi chọn một thành phố, kiểm tra xem chi phí hiện tại có khả thi (< kq) không.
// Nếu thăm đủ n-1 thành phố, tính chi phí quay lại 0, cập nhật kq nếu nhỏ hơn.
// Quay lui để thử các đường khác, in kq cuối cùng.



#include <iostream>
using namespace std;

int a[20][20]; // Ma trận chi phí: a[i][j] là chi phí từ thành phố i đến j
int n; // Số thành phố
bool used[20]; // Mảng đánh dấu thành phố đã được thăm
int kq; // Lưu chi phí nhỏ nhất tìm được

// Hàm quay lui: i là số thành phố đã thăm, cur là thành phố hiện tại, sum là tổng chi phí hiện tại
void quayLui(int i, int cur, int sum) {
    // Thử chọn thành phố tiếp theo (j từ 1 đến n-1, vì thành phố 0 là điểm đầu)
    for(int j = 1; j < n; j++) {
        // Nếu thành phố j chưa được thăm và chi phí hiện tại + chi phí đến j nhỏ hơn kết quả tốt nhất
        if(!used[j] && sum + a[cur][j] < kq) {
            used[j] = true; // Đánh dấu j đã thăm
            sum += a[cur][j]; // Cộng chi phí đi từ cur đến j
            // Nếu đã thăm đủ n-1 thành phố (trừ thành phố 0), tính chi phí quay lại 0
            if(i == n - 2) {
                kq = min(kq, sum + a[j][0]); // Cập nhật chi phí nhỏ nhất
            }
            else {
                // Tiếp tục thử cho thành phố tiếp theo
                quayLui(i + 1, j, sum);
            }
            sum -= a[cur][j]; // Bỏ chi phí vừa cộng (quay lui)
            used[j] = false; // Bỏ đánh dấu j (quay lui)
        }
    }
}

int main() {
    // Nhập input
    cin >> n;
    for(int i = 0; i < n; i++) {
        used[i] = false; // Khởi tạo mảng used
        for(int j = 0; j < n; j++) {
            cin >> a[i][j]; // Nhập ma trận chi phí
        }
    }
    kq = 1e9; // Khởi tạo kết quả là số rất lớn
    quayLui(0, 0, 0); // Bắt đầu từ thành phố 0, chưa thăm thành phố nào, chi phí ban đầu = 0
    cout << kq; // In kết quả
    return 0;
}


// Điều kiện sum + a[cur][j] < kq giúp loại bỏ các nhánh không tối ưu:
// Nếu chi phí hiện tại (sum) cộng với chi phí đi đến thành phố tiếp theo (a[cur][j]) đã lớn hơn hoặc bằng kq (chi phí nhỏ nhất tìm được), thì bỏ nhánh đó.
// Điều này giảm số lượng đường đi cần thử, đặc biệt với n lớn.




// #include <bits/stdc++.h>
// using namespace std;
//
// int n, minKc, ans;
// int a[20][20], vs[20];
//
// void Try(int ind, int cou, int val) {
//     //! nếu chi phí hiện tại + chi phí tối thiểu để đi (n - k + 1) tp còn lại >= ans thì k cần đi nữa vì chắc chắn k tối ưu
//     if (val + minKc * (n - cou + 1) >= ans) return;
//     if (cou == n) {
//         val += a[ind][1];
//         ans = min(ans, val);
//         return;
//     }
//     for (int i = 2; i <= n; ++i) {
//         if (vs[i] == 0) {
//             vs[i] = 1;
//             Try(i, cou + 1, val + a[ind][i]);
//             vs[i] = 0;
//         }
//     }
// }
//
// void testCase() {
//     minKc = ans = INT_MAX;
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             cin >> a[i][j];
//             minKc = min(minKc, a[i][j]);
//         }
//     }
//     vs[1] = 1;
//     Try(1, 1, 0);
//     cout << ans;
// }
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//
//     int T = 1;
//     while (T--) {
//         testCase();
//         cout << "\n";
//     }
//     return 0;
// }
//
