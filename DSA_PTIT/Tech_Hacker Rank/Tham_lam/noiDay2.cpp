//
// Created by TDG on 29/06/2025.
//
#include <bits/stdc++.h>
using namespace std;
main() {
    cin.tie(0)->sync_with_stdio(0);
    priority_queue<long long> q;
    int n; cin>>n;
    for (int i = 0; i < n; i++) {
        long long x; cin>>x;
        q.push(x);
    }
    long long ans=0;
    int mod=1e9+7;
    while (q.size()>1) {
        long long t1 = q.top(); q.pop();
        long long t2 = q.top(); q.pop();
        ans=ans+(t1+t2)%mod;
        ans=ans%mod;
        q.push(t1+t2);
    }
    cout<<ans;
}
