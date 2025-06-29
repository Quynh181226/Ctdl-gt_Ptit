#include <bits/stdc++.h>
using namespace std;
void solve() {
    //so lan toi da dc phep giam tan suat
    int k; cin >> k;
    string s; cin >> s;
    int a[127]={};
    // for (char c : s) a[c]++;
    for (int i = 0; i < s.length(); i++) a[s[i]]++;
    priority_queue<int> q;
    //dua cac tan suat > 0 vao prior
    //duyet qua tung ptu trg a
    //neu tan suat i>0((ky tu ton tai trg xau)" con=0 la ko ton tai nen loai bo tranh duyet vo nghia ")
    //day tan suat vao max-heap
    //so ky can loai bo
    //xau ky tu dau vao
    //dem tan suat xuat hien cua cac ky tu
    //tang gtri tai vtri tuong ung vs ma ASCII cua ky tu
    // for (int i: a) {
    //     if (i>0) q.push(i);
    // }
    for (int i = 0; i < 127; i++) {
        if (a[i]>0) q.push(a[i]);
    }
    while(k--){
        if(q.empty()) break;
        //luu gtri tan suat lon nhat
        int x=q.top(); q.pop();
        if (x>0) {
            x--;
            q.push(x);
        }
    }
    long long ans=0;
    while(!q.empty()){
        //tan suat + tinh tong binh phuong
        long long y=q.top(); q.pop();
        ans+=y*y;
    }
    cout<<ans;
}
main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}
