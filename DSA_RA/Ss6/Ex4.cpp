#include<iostream>
#include <vector>
using namespace std;
main() {
    int n, pos, value;
    cin>>n;
    if (n<=0; n>100) return 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    cin>>pos>>value;
    if (pos<0|| pos>n) return 1;
    a[pos]=value;
    for (int i = 0; i < n; i++) cout<<a[i]<<" ";
}