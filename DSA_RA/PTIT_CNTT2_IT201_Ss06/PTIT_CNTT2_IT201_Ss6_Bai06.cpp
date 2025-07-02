#include<bits/stdc++.h>
using namespace std;
int wayUpStairs(int n){
//da leo het
if(n==0||n==1) return 1;
if(n<0) return 0;
return wayUpStairs(n-1)+wayUpStairs(n-2);
}
main(){
int n; cin>>n;
cout<<wayUpStairs(n);
}