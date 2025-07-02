#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int sort(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
main() {
    int  n; scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int x; scanf("%d", &x);
    qsort(a, n, sizeof(int), sort);
    int l=0, r=n-1, check=0;
    while (l<=r) {
        int m=(l+r)/2;
        if (a[m]==x) {
            printf("pos: %d", m+1);
            check=1;
            break;
        }
        if (a[m]<x){
            l=m+1;
        }else {
            r=m-1;
        }
    }
    // return -1;
    if (!check) printf("Not found");
}