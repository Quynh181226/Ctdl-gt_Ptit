#include<stdio.h>
main() {
    int n; scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) {
        int key=a[i], j=i-1;
        while (j>=0&&a[j]>key) {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for (int i=0; i<n; i++) printf("%d ",a[i]);
}