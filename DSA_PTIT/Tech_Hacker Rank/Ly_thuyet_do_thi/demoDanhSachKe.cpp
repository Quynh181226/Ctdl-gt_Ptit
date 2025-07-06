//
// Created by TDG on 06/07/2025.
//
#include <bits/stdc++.h>
using namespace std;
int n, m;
// vector chứa mảng các danh sách kề
vector<int> ke[1005];
main() {
// [Graph].Bài 1. Chuyển danh sách cạnh sang danh sách kề
// Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển
// đổi đồ thị dưới dạng danh sách cạnh này sang danh sách kề tương ứng.
// Input Format
// Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các
// đỉnh của đồ thị được đánh số từ 1 tới n. M dòng tiếp theo mỗi dòng chứa đỉnh u, v
// tương ứng với một cạnh của đồ thị.
// Constraints
// 1<=n<=1000; 1<=m<=n*(n-1)/2;
//     Output Format
//     In ra n dòng, trong đó dòng thứ i in ra danh sách kề của đỉnh i. Các đỉnh trong
//     danh sách kề được liệt kê từ nhỏ tới lớn.
//     Sample Input 0
//     5 4
//     2 5
//     4 1
//     4 2
//     4 3
//     Sample Output 0
//     1 : 4
//     2 : 4 5
//     3 : 4
//     4 : 1 2 3
//     5 : 2
    //vd cho 1 danh sách cạnh in ra danh sach ke tuong ung
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        //ngược lại và gấp đôi chỉ áp dụng cho đồ thị vô hướng
        //còn có hướng thì chỉ push_back bổ sung cạnh kề cho 1 cái thôi
        //  ke[x].push_back(y);
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 1; i <=n; i++) {
        cout<<i<<": ";
        sort(ke[i].begin(), ke[i].end());
        for (int j = 0; j < ke[i].size(); j++) {
            cout<<ke[i][j]<<" ";
        }
        cout<<endl;
    }
}