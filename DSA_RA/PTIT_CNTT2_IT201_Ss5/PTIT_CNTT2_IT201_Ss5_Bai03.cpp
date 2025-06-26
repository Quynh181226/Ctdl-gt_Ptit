//tinh giai thua of 1 integer
//n! = n * (n-1) * (n-2) * ... * 1
//0!=1 and 1!=1
//n==0 or n==1 => n!=1
//n>1 => n!=n*(n-1)!
#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
if(n==0 || n==1) return 1;
return n*factorial(n-1);
}
main(){
int n; cin>>n;
if(n<1) cout<<"Invalid";
else cout<<factorial(n);
}