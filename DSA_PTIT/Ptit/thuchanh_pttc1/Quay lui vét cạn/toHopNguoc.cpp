//
// Created by TDG on 22/05/2025.
//
// Hãy liệt kê tất cả các tổ hợp chập K của N số nguyên dương đầu tiên theo thứ tự ngược (tức là thứ tự giảm dần).
//
// Input
// Dòng đầu ghi số bộ test T (T<10)
// Mỗi bộ test viết trên một dòng 2 số N và K (1 < K < N < 20)
//
// Output
// Với mỗi bộ test, ghi lần lượt các tổ hợp theo thứ tự ngược. Mỗi tổ hợp trên một dòng.
//
// Input
// 1
// 5 3
// Output
// 3 4 5
// 2 4 5
// 2 3 5
// 2 3 4
// 1 4 5
// 1 3 5
// 1 3 4
// 1 2 5
// 1 2 4
// 1 2 3


//giam dan
//1
// 5 3
//
// 5 4 3
// 5 4 2
// 5 4 1
// 5 3 2
// 5 3 1
// 5 2 1
// 4 3 2
// 4 3 1
// 4 2 1
// 3 2 1
// #include<iostream>
// using namespace std;
//
// int n, k, arr[20];
//
// void in() {
//     for (int i = 1; i <= k; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
//
// void quaylui(int i) {
//     for (int j = arr[i - 1] - 1; j >= k - i + 1; j--) {
//         arr[i] = j;
//         if (i == k) in();
//         else quaylui(i + 1);
//     }
// }
//
// int main() {
//     int t;
//     cin >> t;
//     if (t >= 10) return 1;
//     while (t--) {
//         cin >> n >> k;
//         if (k <= 1 || k >= n || n >= 20) return 1;
//         arr[0] = n + 1;
//         quaylui(1);
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

int n, k, arr[20];

void in() {
    for (int i = 1; i <= k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quaylui(int i) {
    for (int j = n - k + i; j >= arr[i - 1] + 1; j--) {
        arr[i] = j;
        if (i == k) in();
        else quaylui(i + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr[0] = 0;
        quaylui(1);
    }
    return 0;
}
