//
// Created by TDG on 26/05/2025.
//
//                       DSU (Union-Find)
// D. Bổ sung cạnh
// time limit per test1 second
// memory limit per test256 megabytes
// Cho đồ thị vô hướng gồm có n đỉnh và m cạnh. Từ đỉnh 1,
// bằng cách duyệt đồ thị, ta có thể đánh dấu được tất cả các
// đỉnh có cùng thành phần liên thông với 1 .
//
// Yêu cầu: Bằng việc thêm đúng 1 cạnh duy nhất vào đồ thị
// (cạnh được thêm chưa xuất hiện trên đồ thị), hãy xác định
// xem số đỉnh tối đa có thể được đánh dấu khi bắt đầu duyệt
// đồ thị từ đỉnh 1 .
//
// Input
// Dòng đầu tiên chứa 2 số nguyên dương n và m (1≤n,m≤105).
// m dòng tiếp theo, mỗi dòng gồm 2 số nguyên dương u,v mô
// tả 1 cạnh của đồ thị (1≤u,v≤n,u≠v).
//
// Output
// Đưa ra số lượng đỉnh tối đa có thể được đánh dấu.
//
// Examples
// Input
// 3 2
// 1 2
// 3 2
// Output
// 3
// Input
// 5 3
// 1 4
// 4 2
// 2 1
// Output
// 4
#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int n, m, d[100005], sz[100005];

// Initialize the DSU
void init(int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = i;
        sz[i] = 1;
    }
}

// Find the root of the set containing u (with path compression)
int find(int u) {
    if (u == d[u]) return u;
    return d[u] = find(d[u]);
}

// Merge two sets containing x and y
void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    d[y] = x;
    sz[x] += sz[y];
}

void solve() {
    cin >> n >> m;
    init(n); // Initialize DSU
    while (m--) {
        int x, y;
        cin >> x >> y;
        union_sets(x, y); // Process each edge
    }
    int mx = 0;
    for (int i = 2; i <= n; i++) {
        int x = find(i);
        if (x > 1) {
            mx = max(mx, sz[x]);
        }
    }
    cout << sz[1] + mx << el;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1; // cin >> tc;
    while (tc--) solve();
}