#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int l, int r, int x){ 
    while(l<=r){
        int m=l+(r-l)/2; 
        if (a[m]==x)   return m; 
        if (a[m] < x)  l=m + 1; 
        else           r=m - 1; 
    } 
    return -1; 
}
main(){
	int t,n,x; cin>>t;
	while(t--){
		cin >> n >> x;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(binarySearch(a,0,n-1,x)!=-1)
			cout << binarySearch(a,0,n-1,x)+1 << endl;
		else cout<<"NO"<<endl;
	}
}
		
