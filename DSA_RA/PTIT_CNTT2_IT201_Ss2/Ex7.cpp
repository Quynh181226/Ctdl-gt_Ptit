#include<bits/stdc++.h>
using namespace std;
main() {
    int n, value;
    cin>>n;
    // vector<int> v(n);
    int v[100];
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>value;
    int check=0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if (v[i]+v[j]==value) {
                check=1;
                cout<<v[i]<<" "<<v[j];
                break;
            }
        }
        if (check==1) break;
    }
    if(check==0) cout<<"Invalid";
}