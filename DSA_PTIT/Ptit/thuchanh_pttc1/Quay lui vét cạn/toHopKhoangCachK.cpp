//
// Created by TDG on 23/05/2025.
//
// Hãy liệt kê các tổ hợp chập K của N số tự nhiên đầu tiên, nhưng chỉ cần liệt kê các tổ hợp cách nhau đúng K vị trí.
// Tức là nếu đánh số thứ tự từ 0 thì cần liệt kê các tổ hợp tại vị trí 0, K, 2K, 3K, … theo thứ tự từ điển.
// Input
// Chỉ có 1 dòng ghi 2 số N và K (2 < N < 30; 2 < K < 15).
// Output
// Ghi ra các tổ hợp thoả mãn trên từng dòng, mỗi số cách nhau 1 khoảng trống.
// Input
// 6 3
// Output
// 1 2 3
// 1 2 6
// 1 3 6
// 1 5 6
// 2 3 6
// 2 5 6
// 3 5 6
#include <iostream>
#include <vector>
using namespace std;

int n, k, pos = 0;
vector<int> arr;

void in() {
    if (pos % k == 0) {
        for (int i = 1; i <= k; i++) {
            cout << arr[i];
            if (i < k) cout << " ";
        }
        cout << endl;
    }
    pos++;
}

void quaylui(int i) {
    for (int j = arr[i - 1] + 1; j <= n - k + i; j++) {
        arr[i] = j;
        if (i == k) in();
        else quaylui(i + 1);
    }
}

int main() {
    cin >> n >> k;
    if (n<=2||n>=30||k<=2||k>=15) return 1;
    arr.resize(k + 1);
    arr[0] = 0;
    quaylui(1);
    return 0;
}
