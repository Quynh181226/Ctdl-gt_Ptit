#include<bits/stdc++.h>
using namespace std;
void nhiphan(int n){
    queue<string> Q;
    Q.push("1");
    while(n--){
        string s = Q.front();
        cout << s << " "; Q.pop();
        Q.push(s + "0");
        Q.push(s + "1");
    }
    cout << endl;
}
main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        nhiphan(n);
    }
}

