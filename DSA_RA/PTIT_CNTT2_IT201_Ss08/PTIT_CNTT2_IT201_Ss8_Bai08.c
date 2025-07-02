#include<stdio.h>
void insert(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int j=i-1, key=a[i];
        while (j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int linear(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i]==x) {
            return i;
        }
    }
    return -1;
}
int binary(int a[], int l, int r, int x) {
    while (l<=r) {
        int m=(l+r)/2;
        if (a[m]==x) {
            return m;
        }
        if (a[m]>x) {
            r=m-1;
        }else {
            l=m+1;
        }
    }
    return -1;
}
main() {
    int n; scanf("%d", &n);
    if (n<=0) return 1;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x; scanf("%d", &x);
    if (linear(a, n, x)!=-1) {
        printf("found\n");
    }else {
        printf("not found\n");
    }
    insert(a, n);
    if (binary(a,0,n-1,x)!=-1) {
        printf("found\n");
    }else {
        printf("not found\n");
    }
}