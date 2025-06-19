#include<iostream>
using namespace std;
main() {
    int n, m , a[100][100];
    cin>>n>>m;
    // Time: O(n * m)
    // Space: O(n * m)
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    if (n==m) {
        for(int i=0;i<n;i++) cout<<a[i][i]<<" ";
        cout<<"\n";
    }
}