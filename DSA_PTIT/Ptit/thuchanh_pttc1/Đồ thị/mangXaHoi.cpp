//
// Created by TDG on 25/05/2025.
//
// Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.
// Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết u và v là kết bạn với nhau trên mạng xã hội của Tý.
// Output:
// Với mỗi test, in ra đáp án tìm được trên một dòng.
// Ví dụ:
// Input:
// 3
// 4 3
// 1 3
// 3 4
// 1 4
// 4 4
// 3 1
// 2 3
// 3 4
// 1 2
// 10 4
// 4 3
// 5 10
// 8 9
// 1 2
// Output
// YES
// NO
// YES
#include <bits/stdc++.h>
using namespace std;

int parent[100001], num[100001], edges[100001];

void Init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        num[i] = 1;
        edges[i] = 0;
    }
}

int Find(int u) {
    if (u != parent[u])
        parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v) {
    int a = Find(u), b = Find(v);
    if (a == b) {
        edges[a]++;
        return;
    }
    if (num[a] < num[b]) swap(a, b);
    parent[b] = a;
    num[a] += num[b];
    edges[a] += edges[b] + 1;
}

bool Solve(int n) {
    vector<bool> check(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int x = Find(i);
        if (!check[x]) {
            check[x] = true;
            long long V = num[x];
            long long E = edges[x];
            if (E != (V * (V - 1)) / 2) return false;
        }
    }
    return true;
}

main() {
    int t;
    cin >> t;
    if (t>20) return 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n>100000||m>100000) continue;
        Init(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        cout << (Solve(n) ? "YES" : "NO") << '\n';
    }
}