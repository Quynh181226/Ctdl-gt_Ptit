//
// Created by TDG on 05/07/2025.
//
//Ma trận kề đồ thị vô hướng
// 6 9
//
// 1 2
//
// 1 3
//
// 1 4
//
// 3 4
//
// 3 5
//
// 3 6
//
// 2 4
//
// 4 6
//
// 5 6
#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int n, m;
main() {
    //đỉnh, cạnh
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        //nhập đỉnh đầu và đỉnh cuối của cạnh
        int x,y; cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
