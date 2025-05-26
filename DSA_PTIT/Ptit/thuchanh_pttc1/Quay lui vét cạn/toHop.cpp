//
// Created by TDG on 23/05/2025.
//
// Cho xâu ký tự S có N chữ số thập phân. Hãy liệt kê các số khác nhau có K chữ số lấy từ K vị trí khác nhau trong xâu S theo thứ tự từ nhỏ đến lớn.
// Input
// Dòng đầu ghi số bộ test T (T < 10).
// Dòng thứ 2 ghi xâu S sau đó là một khoảng trống rồi đến số K (1 < K < N < 20).
// Output
// Với mỗi bộ test, ghi ra lần lượt các số khác nhau tạo được theo thứ tự từ nhỏ đến lớn.
// Input
// 2
// 1234 2
// 4444 2
// Output
// 12
// 13
// 14
// 23
// 24
// 34
// 44
#include <iostream>
#include <set>
#include <string>
using namespace std;

int n, k;
string s;
int pos[20]; // Lưu các vị trí được chọn
set<long long> numbers; // Lưu các số khác nhau

// Tạo số từ K vị trí đã chọn
void makeNumber() {
    long long num = 0;
    for (int i = 1; i <= k; i++) {
        num = num * 10 + (s[pos[i]] - '0');
    }
    numbers.insert(num);
}

// Sinh tổ hợp vị trí
void quaylui(int i, int start) {
    for (int j = start; j < n - k + i; j++) {
        pos[i] = j;
        if (i == k) {
            makeNumber();
        } else {
            quaylui(i + 1, j + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    if (t >= 10) return 1;

    while (t--) {
        cin >> s >> k;
        n = s.length();
        if (k <= 1 || k >= n || n >= 20) {
            continue;
        }

        numbers.clear(); // Xóa set cho bộ test mới
        quaylui(1, 0); // Bắt đầu sinh tổ hợp vị trí

        // In các số theo thứ tự từ nhỏ đến lớn
        for (long long num : numbers) {
            cout << num << endl;
        }
    }
    return 0;
}