//n so fibo dau tien
#include <bits/stdc++.h>
using namespace std;

long long fibo(int n, int i, int f1, int f2) {
    if (i>=n) return 0;
    int fn=f1+f2;
    // f2=f1;
    // f1=fn;
    printf("%d ", fn);
    return fibo(n,i+1, f2, fn);
}

main() {
    int n; cin >> n;
    if (n<=0) {
        printf("Invalid");
        return 0;
    }
    if (n>=1) printf("0 ");
    if (n>=2) printf("1 ");
    fibo(n,2, 0, 1);
}