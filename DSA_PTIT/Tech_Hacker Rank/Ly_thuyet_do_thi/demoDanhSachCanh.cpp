//
// Created by TDG on 05/07/2025.
//
//Danh sách cạnh đồ thị vô hướng

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
