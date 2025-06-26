//tinh tong tu n->m
#include <bits/stdc++.h>
using namespace std;
int sum(int n, int m) {
if(n<0 || m<0 || n>m) return -1;
if(n==m) return n;
return n+sum(n+1, m);
}
main(){
int n, m;
cin>>n>>m;
if(sum(n,m) == -1) cout<<"Invalid";
else cout<<sum(n,m);
}