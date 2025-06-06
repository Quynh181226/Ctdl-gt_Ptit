// DSA09032 - KẾT BẠN
// Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của C thì A và C cũng là bạn bè của nhau.
// Các bạn hãy xác định xem số lượng sinh viên nhiều nhất trong một nhóm bạn là bao nhiêu?
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết sinh viên u là bạn của sinh viên v.
// Output:
// Với mỗi test, in ra đáp án tìm được trên một dòng.
// Ví dụ:
// Input:
// 2
// 3 2
// 1 2
// 2 3
// 10 12
// 1 2
// 3 1
// 3 4
// 5 4
// 3 5
// 4 6
// 5 2
// 2 1
// 7 1
// 1 2
// 9 10
// 8 9
// Output
// 3
// 7
#include <bits/stdc++.h>
using namespace std;
int n, m, ans, parent[100001], num[100001];
void Init(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        num[i] = 1;
    }
}
int Find(int u){
    if(u != parent[u])
        parent[u] = Find(parent[u]);
    return parent[u];
}
void Union(int u, int v){
    int a = Find(u), b = Find(v);
	if(a == b) return;
	if (num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
	ans = max(ans, num[a]);
}
main() {
    int t,u,v; cin >> t;
    while(t--){
        ans = 0; cin >> n >> m;
        Init();
        while(m--){
            cin >> u >> v;
            Union(u, v);
        }
        cout << ans << endl;
    }
}
