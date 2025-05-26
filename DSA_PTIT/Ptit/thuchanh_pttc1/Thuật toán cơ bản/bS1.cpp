#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
main(){
	int t,i,kq;cin>>t;
	while(t--){
		cin >> n >> k;
		for(i=0;i<n;i++) cin>>a[i];
		vt = lower_bound(a,a+n,k) - a;
		if(a[vt] == k) cout << vt+1 << endl;
		else cout<<"NO"<<endl;
	}
}