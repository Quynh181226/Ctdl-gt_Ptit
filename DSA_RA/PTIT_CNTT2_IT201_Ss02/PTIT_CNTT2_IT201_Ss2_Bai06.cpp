// Thuật toán :
//
// Dịch các phần tử từ chỉ số K tới chỉ số N - 1 trong mảng sang phải 1 phần tử, việc dịch sẽ được thực hiện từ phải sang trái.
// Gán A[K] = X
// Tăng N lên 1 đơn vị
#include<bits/stdc++.h>
using namespace std;
main() {
    int n, pos, value; cin>>n;
    if (n<=0||n>100) return 1;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>pos>>value;
    if (pos<0||pos>=a.size()) return 1;
    //c1
    a.insert(a.begin()+pos, value);
    //c2
    // a.push_back(0);
    // for (int i=n-1; i>=pos; i--) {
    //     a[i+1]=a[i];
    // }
    //a[pos]=value;
    // ++n;
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
}
