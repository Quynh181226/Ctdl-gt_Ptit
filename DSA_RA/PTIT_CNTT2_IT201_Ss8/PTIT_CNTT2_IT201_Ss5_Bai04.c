#include<stdio.h>
main() {
    int n; scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    int min, tmp;
    for (int i=0; i<n-1; i++) {
        min=i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[min]) {
                min=j;
            }
        }
        tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
    for (int i=0; i<n; i++) printf("%d ",a[i]);
}