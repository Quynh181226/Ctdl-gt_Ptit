//
// Created by TDG on 22/05/2025.
//
// DSA01005 - SINH HOÁN VỊ
// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N.
// Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.
// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
// Input	Output
// 2 2 3	12 21 123 132 213 231 312 321

#include <iostream>
#include <cstring>

using namespace std;

int a[100]; // Mảng lưu hoán vị hiện tại
int n; // Số N, xác định dãy số từ 1 đến N
bool used[100]; // Mảng đánh dấu số nào đã được dùng trong hoán vị hiện tại

// Hàm quay lui để sinh hoán vị
void quayLui(int i) {
    // Thử từng số từ 1 đến n cho vị trí i
    for(int j = 1; j <= n; j++) {
        if(!used[j]) { // Nếu số j chưa được dùng
            a[i] = j; // Gán số j vào vị trí i
            used[j] = true; // Đánh dấu số j đã dùng
            if(i == n - 1) { // Nếu đã điền đủ các vị trí
                // In hoán vị hiện tại
                for(int idx = 0; idx < n; idx++) {
                    cout << a[idx];
                }
                cout << " "; // Khoảng trắng giữa các hoán vị
            }
            else {
                // Gọi đệ quy để điền vị trí tiếp theo
                quayLui(i + 1);
            }
            used[j] = false; // Quay lui: bỏ đánh dấu số j để thử số khác
        }
    }
}

main() {
    cin.tie(0)->sync_with_stdio(0); // Tối ưu tốc độ nhập/xuất
    int t; // Số lượng test case
    cin >> t;
    while(t--) { // Xử lý từng test case
        cin >> n; // Đọc N cho test case hiện tại
        memset(used, false, sizeof(used)); // Khởi tạo mảng used về false
        quayLui(0); // Bắt đầu quay lui từ vị trí 0
        cout << '\n'; // Xuống dòng sau mỗi test case
    }
}