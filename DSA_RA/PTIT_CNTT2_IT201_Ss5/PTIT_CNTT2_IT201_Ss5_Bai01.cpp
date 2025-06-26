// Xây dựng chương trình yêu cầu người dùng nhập vào một số nguyên dương bất kỳ
// Sử dụng đệ quy, in ra lần lượt các phần tử từ 1 đến n
#include <bits/stdc++.h>
using namespace std;
void in(int n) {
    if (n>0) {
        // in tu 1->n-1
        in(n-1);
        cout<<n<<'\n';
    }
}
main() {
    int n; cin>>n;
    if(n<=0) return 1;
    else in(n);
}

