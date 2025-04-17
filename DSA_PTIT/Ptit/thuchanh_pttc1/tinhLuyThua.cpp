#include<bits/stdc++.h>
int m=1e9+7;
long long power(int n, int k){
    if(k==0) return 1;
    long long x=power(n, k/2);
    if(k%2==0) return x*x%m;
    return n*(x*x%m)%m;
}
using namespace std;
main(){
    int t, n, k;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        cout<<power(n, k)<<endl
    }
    
}