//tinh tong tu 1->n
#include <bits/stdc++.h>
using namespace std;
int total(int n) {
    //n=0 total=0
    if (n==0) return 0;
    return n+total(n-1);
}
main() {
    int n; cin>>n;
    if(n<=0) cout<<"Invalid";
    else cout<<total(n);
}
