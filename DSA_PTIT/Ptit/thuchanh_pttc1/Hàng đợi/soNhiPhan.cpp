#include <bits/stdc++.h>
using namespace std;
void nhiphan(int n){
    queue<string> q;
    q.push("1");
    while (n--)
    {
        string s=q.front();
        cout<<s<<" "; q.pop();
        q.push(s+"0");
        q.push(s+"1");
    }
    cout<<endl;
}
main(){
    int t, n;
    cin>>t;
    while (t--){
        cin>>n;
        nhiphan(n);
    }
}