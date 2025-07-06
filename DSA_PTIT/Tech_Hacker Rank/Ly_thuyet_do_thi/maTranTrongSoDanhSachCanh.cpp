//
// Created by TDG on 06/07/2025.
//
// [Graph]. Bài 8. Ma trận trọng số sang danh sách cạnh
// Cho đồ thị vô hướng G = được biểu diễn dưới ma trận trọng số A[][], trong đó A[i]
// [j] khác không có nghĩa có cạnh nối giữa 2 đỉnh i, j. Hãy chuyển đồ thị đã cho
// thành danh sách cạnh tương ứng.
// Input Format
// Dòng đầu tiên là n, tương ứng là số lượng đỉnh của đồ thị. N dòng tiếp theo là ma
// trận A[][].
// Constraints
// 1<=n<=1000; 1<=A[i][j]<=10^6;
// Output Format
// In ra danh sách cạnh và trọng số theo thứ tự đỉnh tăng dần.
// Sample Input 0
// 5
// 0 0 9 4 1
// 0 0 1 0 6
// 9 1 0 3 1
// 4 0 3 0 8
// 1 6 1 8 0
// Sample Output 0
// 1 3 9
// 1 4 4
// 1 5 1
// 2 3 1
// 2 5 6
// 3 4 3
// 3 5 1
// 4 5 8
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ke[1005];
int a[1005][1005];
main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
           if (i<j&&a[i][j]!=0) {
               cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
           }
        }
    }
}