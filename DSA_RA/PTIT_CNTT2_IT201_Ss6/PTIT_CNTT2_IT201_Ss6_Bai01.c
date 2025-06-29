#include<stdio.h>
void binary(int n){
    if(n==0) return;
    binary(n/2);
    printf("%d", n%2);
}
main(){
    int n; scanf("%d",&n);
    if(n==0) printf("0");
    else binary(n);
}