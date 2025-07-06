//
// Created by TDG on 06/07/2025.
//
// [Graph]. Bài 5. Ma trận kề sang danh sách kề, danh sách cạnh
// (vô hướng).
// Cho ma trận kề A[][] của đồ thị vô hướng G = chỉ bao gồm các số 0 hoặc 1. Hãy
// chuyển đổi đồ thị này thành danh sách cạnh và danh sách kề tương ứng.
// Input Format
// Dòng đầu tiên là n tương ứng với số lượng đỉnh của đồ thị. n dòng tiếp theo mỗi
// dòng gồm n số mô tả ma trận A
// Constraints
// 1<=n<=1000
// Output Format
// Những dòng đầu tiên liệt kê danh sách cạnh theo thứ tự từ điển tăng dần, mỗi
// cạnh chỉ liệt kê một lần và liệt kê đỉnh bắt đầu là đỉnh lớn hơn. Sau đó cách ra 1
// dòng và liệt kê danh sách kề, trong đó các đỉnh trong danh sách kề được in ra
// theo thứ tự tăng dần. Xem output mẫu để rõ hơn.
// Sample Input 0
// 5
// 0 1 1 1 0
// 1 0 0 1 1
// 1 0 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
//
// Sample Output 0
// 2 1
// 3 1
// 4 1
// 4 2
// 4 3
// 5 2
// 5 3
// 5 4
// 1 : 2 3 4
// 2 : 1 4 5
// 3 : 1 4 5
// 4 : 1 2 3 5
// 5 : 2 3 4
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ke[1005];
int a[1005][1005];
main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> dscanh;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
            if (a[i][j]==1) {
                ke[i].push_back(j);
            }
            if (i<j&&a[i][j]==1) {
                dscanh.push_back({j,i});
            }
        }
    }
    sort(dscanh.begin(), dscanh.end());
    for (auto i : dscanh) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    for (int i=1; i<=n; i++) {
        sort(ke[i].begin(), ke[i].end());
        cout<<i<<": ";
        for (int x: ke[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}