//
// Created by TDG on 29/06/2025.
//
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
main() {
    cin.tie(0)->sync_with_stdio(0);
    //min heap
    priority_queue<ll, vector<ll>, greater<ll>> q;
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        ll x; cin>>x;
        q.push(x);
    }
    ll ans=0;
    while(q.size()>1) {
        ll t1=q.top(); q.pop();
        ll t2=q.top(); q.pop();
        ans=ans+(t1+t2);
        q.push(t1+t2);
    }
    cout<<ans;
}