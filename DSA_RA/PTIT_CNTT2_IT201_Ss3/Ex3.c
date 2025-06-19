#include<stdio.h>
#include <stdlib.h>

float average(int a[], int n) {
    int cnt=0, total = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]%2==0) {
            total += i;
            cnt++;
        }
    }
    if (cnt==0) return 0;
    return (float)total/cnt;
}
main() {
    int n; scanf("%d",&n);
    if (n<=0||n>=1000) {
        printf("Invalid");
        return 1;
    }
    int *a=(int *)malloc(n*sizeof(int));
    if (a==NULL) return 1;
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    printf("Average=%.0f", average(a,n));
    free(a);
}