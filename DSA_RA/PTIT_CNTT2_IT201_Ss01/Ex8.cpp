#include <iostream>
#include <vector>
using namespace std;
main() {
    int n; cin>>n;
    // int a[100];
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int temp, maxCnt=0;
    // Time: O(n^2)
    // Space: O(n)
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            if(a[i]==a[j]) {
                cnt++;
            }
        }
        if (cnt>maxCnt) {
            maxCnt=cnt;
            temp=a[i];
        }
    }
    cout<<temp;
}