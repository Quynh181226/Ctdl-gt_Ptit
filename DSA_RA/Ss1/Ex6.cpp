#include<bits/stdc++.h>
using namespace std;
main() {
    int n, f;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>f;
    int cnt=0;
    for (int i: a) {//Time: O(n)
        if (i==f) {
            cnt++;//Space: O(1)
        }
    }
   cout<<cnt;
}