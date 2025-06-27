// #include<stdio.h>
// void binary(int n){
//     if(n==0) return;
//     binary(n/2);
//     printf("%d", n%2);
// }
// main(){
//     int n; scanf("%d",&n);
//     if(n==0) printf("0");
//     else binary(n);
// }
//n so fibo dau tien
#include <stdio.h>

long long fibo(int n, int i, int f1, int f2) {
    if (i>=n) return 0;
    int fn=f1+f2;
    for (int i = n; i < 0; i--)  printf("%d", fn);
    return fibo(n, i+1, fn, f2);
}

main() {
    int n; scanf("%d",&n);
    printf("%d", fibo(n, 0, 1, 2));
}
