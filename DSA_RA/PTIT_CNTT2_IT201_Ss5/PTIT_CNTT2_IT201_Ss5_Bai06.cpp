//tong arr
#include<bits/stdc++.h>
using namespace std;
int sumArr(int n, vector<int> v){
if(n==0) return 0;
return sumArr(n-1, v) + v[n-1];
}
main(){
int n; cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++) cin>>v[i];
cout<<sumArr(n, v);
}