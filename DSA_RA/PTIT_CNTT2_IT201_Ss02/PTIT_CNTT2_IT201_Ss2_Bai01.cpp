#include<iostream>
#include<vector>
using namespace std;
main(){
int n; cin>>n;
    vector<int> a(n);
if(n<=0||n>100) return 1;
for (int i=0; i<n; i++) cin>>a[i];
int max=a[0];
for (int i=1; i<n; i++) {
    if (a[i]>max) {
        max=a[i];
    }
}
cout<<max;
}