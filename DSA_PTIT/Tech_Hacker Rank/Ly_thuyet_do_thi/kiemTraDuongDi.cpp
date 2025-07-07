//
// Created by TDG on 07/07/2025.
//
// [Graph]. Bài 18. Kiểm tra đường đi
// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Có Q
// truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường
// đi tới nhau hay không ?
// Input Format
//
// Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các
// đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v
// (u != v) tương ứng với một cạnh của đồ thị. Dòng tiếp theo là Q, Q dòng tiếp theo
// mỗi dòng chứa 2 đỉnh s, t cần truy vấn.
// Constraints
// 1<=s,t<=n<=1000; 1<=m<=n*(n-1)/2; 1<=Q<=10000;
// Output Format
// Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.
// ==> giải pháp là check 2 truy vấn xem có cùng thành phần liên thông hay không
// Sample Input 0
// 5 3
// 5 4
// 4 1
// 4 3
// 3
// 4 5
// 4 2
// 3 4
// Sample Output 0
// 1
// -1
// 1
#include<bits/stdc++.h>
using namespace std;
int n, m, cnt=0;
vector<int> ke[10001];
int visited[10001], tplt[10001];
void nhap() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        ke[i].clear();
        visited[i]=0;
        tplt[i]=0;
    }
    for(int i=0;i<m;i++) {
        int x,y; cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}
void dfs(int x) {
    tplt[x]=cnt;
    visited[x] = 1;
    for (int v: ke[x]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
main() {
    nhap();
    cnt=0;
    for(int i=1;i<=n;i++)
        if (!visited[i]) {
            dfs(i);
            ++cnt;
        }
    int t; cin>>t;
    while(t--) {
        int u, v; cin>>u>>v;
        //MANG visted CAN PHAI DC RESET = 0 NEU KHONG "NÓ SẼ THĂM HẾT CÁC ĐỈNH" VA BI "CHONG HET LẠI VỚI NHAU"
        // memset(visited, 0, sizeof(visited));
        // dfs(u);
        // if (visited[v]==1) {
        if (tplt[u]==tplt[v]){
            cout<<1<<endl;
        }else {
            cout<<-1<<endl;
        }
    }
}