#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &a, int n) {
    for (int i=0; i<n/2; i++) {
        int temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
}
main() {
    int n; cin>>n;
    vector<int> a(n);
    if (n<=0||n>100) return 1;
    for(int i=0;i<n;i++) cin>>a[i];
    reverse(a, n);
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
}