//
// Created by TDG on 28/05/2025.
//

// BCCAITUI - Cái Túi
//
// Trong siêu thị có n gói hàng (n <= 100), gói hàng thứ i có trọng lượng là Wi <= 100
// và giá trị Vi <= 100. Một Tên trộm đột nhập vào siêu thị, sức của tên trộm không thể
// mang được trọng lượng vượt quá M (M <= 100). Hỏi tên trộm sẽ lấy đi những gói hàng nào
// để được tổng giá trị lớn nhất.
//
// Input
// Dòng đầu tiên gồm 2 số nguyên n và M (n <= 100, M <= 100)
// Trên n dòng tiếp theo, mỗi dòng chứa 2 số nguyên Wi và Vi (Wi, Vi <= 100) lần lượt
// là trọng lượng và giá trị của gói hàng thứ i.
//
// Output
// Giá trị lớn nhất tên trộm lấy được.
//
// Example
// Input:
// 3 4
// 1 4
// 2 5
// 3 6
//
// Output:
// 10

#include <bits/stdc++.h>
using namespace std;

int n, M; // n: số vật phẩm, M: sức chứa túi

struct Data {
    int wei; // Trọng lượng của vật phẩm
    int val; // Giá trị của vật phẩm
} a[105]; // Mảng lưu n vật phẩm

// Hàm so sánh để sắp xếp theo tỉ lệ giá trị/trọng lượng (giảm dần)
bool cmp(Data a, Data b) {
    return (double)a.val / a.wei > (double)b.val / b.wei;
}

// Hàm quay lui: i là chỉ số vật phẩm hiện tại, W là tổng trọng lượng đã chọn, V là tổng giá trị
int Try(int i, int W, int V) {
    // Nếu tổng trọng lượng vượt quá M, đường đi này không hợp lệ
    if (W > M)
        return 0;
    // Nếu đã xét hết n vật phẩm và W <= M, trả về giá trị hiện tại
    if (i == n && W <= M)
        return V;
    // Lựa chọn 1: Lấy vật phẩm i (nếu còn trong giới hạn trọng lượng)
    int x = Try(i + 1, W + a[i].wei, V + a[i].val);
    // Lựa chọn 2: Không lấy vật phẩm i
    int y = Try(i + 1, W, V);
    // Trả về giá trị lớn nhất giữa hai lựa chọn
    return max(x, y);
}

int main() {
    // Nhập input
    cin >> n >> M;
    for (int i = 0; i < n; i++)
        cin >> a[i].wei >> a[i].val;

    // Sắp xếp vật phẩm theo tỉ lệ giá trị/trọng lượng giảm dần
    sort(a, a + n, cmp);
    // Gọi hàm quay lui từ vật phẩm 0, trọng lượng ban đầu 0, giá trị ban đầu 0
    cout << Try(0, 0, 0);
    return 0;
}