#include<stdio.h>
#include <stdlib.h>
void merge(int a[], int m, int l, int r) {
    int n1=m-l+1, n2=r-m;
    int *aLeft=(int*)calloc(n1, sizeof(int));
    int *aRight=(int*)calloc(n2, sizeof(int));
    for(int i=0; i<n1; i++) {
        aLeft[i]=a[i+l];
    }
    for(int j=0; j<n2; j++) {
        aRight[j]=a[j+1+m];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(aLeft[i]<=aRight[j]) {
            a[k++]=aLeft[i];
            i++;
        }else {
            a[k++]=aRight[j];
            j++;
        }
    }
    while(i<n1) {
        a[k++]=aLeft[i];
        i++;
    }
    while(j<n2) {
        a[k++]=aRight[j];
        j++;
    }
    free(aLeft);
    free(aRight);
}
void mergeSort(int a[], int l, int r) {
    if (l<r) {
        int m=l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, m, l, r);
    }
}
void print(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
main() {
    int n; scanf("%d",&n);
    if (n<=0) {
        printf("Invalid");
        return 1;
    }
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("before = ");
    print(a,n);
    mergeSort(a,0,n-1);
    printf("\nafter = ");
    print(a,n);
}