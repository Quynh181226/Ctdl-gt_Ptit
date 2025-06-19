#include<bits/stdc++.h>
using namespace std;
main() {
    int n, pos; cin>>n;
    if (n<=0||n>100) return 1;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>pos;
    if (pos<0||pos>=a.size()) return 1;
    //c1
    a.erase(a.begin()+pos);
    //c2
    // for (int i=pos; pos<n-1; i++) {
    //     a[i]=a[i+1];
    // }
    //a.pop_back();
    // n--;
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
}