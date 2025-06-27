//n so fibo dau tien
#include <stdio.h>

long long fibo(int n, int i, int f1, int f2) {
    if (i>n) return;
    int fn=f1+f2;
    fibo(n, i+1, f2, fn);
    if (i<=n) printf("%d ", f1);
}
int fibo1(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    return fibo1(n-1)+fibo1(n-2);
}
void reverse(int n) {
    for (int i=n; i>0; i--) {
        printf("%d ", fibo1(i));
    }
}
main() {
int n; scanf("%d",&n);
    if (n<=0) {
        printf("Invalid");
        return 0;
    }
    fibo(n, 1, 1, 1);
    printf("\n");
    reverse(n);
}