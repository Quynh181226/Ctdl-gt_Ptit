#include <bits/stdc++.h>
using namespace std;
//Time complexity: O(n log n): insert, find
//Space complexity: O(n) set save n ptu da duyet
bool dupli1(int a[], int n) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        //trung lap
        if (s.find(a[i])!=s.end()) {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}
//Time complexity: O(n^2)
bool dupli2(int a[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i]==a[j]) return true;//Space complexity: O(1)
        }
    }
    //not dupli
    return false;
}
main() {
    int n; cin>>n;
    if (n<0||n>1000) {
        return 1;
    }
    int a[1000];
    // vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]<0|| a[i]>1000) return 1;
    }
    cout<<(dupli1(a, n)?"Dupli":"No Dupli")<<"\n"<<(dupli2(a, n)?"Dupli":"No Dupli");
}