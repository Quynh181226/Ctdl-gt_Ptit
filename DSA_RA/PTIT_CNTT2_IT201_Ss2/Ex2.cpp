#include<iostream>
#include <vector>
using namespace std;
main() {
int n, f;
    cin>>n;
    vector<int> a(n);
    if (n<=0|| n>100) return 1;
    for (int i = 0; i < n; i++) cin>>a[i];
    cin>>f;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]==f) {
            cnt++;
        }
    }
    cout<<cnt;
}