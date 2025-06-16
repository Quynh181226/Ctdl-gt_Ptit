#include <iostream>
using namespace std;

//S1: Time complexity: duyệt O(n)
//    Space complexity: biến +> O(1)
long long tong1(int n) {
    long long sum=0;
    for(int i=1;i<=n;i++) sum+=i;
    return sum;
}
//S2: Time complexity: O(1)
//    Space complexity: biến lưu kqua +> O(1)
long long tong2(int n) {
    return n*(n+1)/2;
}

main() {
    int n; cin>>n;
    if (n<1) return 1;
    cout<<"S1: "<<tong1(n)<<"\n"<<"S2: "<<tong2(n)<<endl;
}
