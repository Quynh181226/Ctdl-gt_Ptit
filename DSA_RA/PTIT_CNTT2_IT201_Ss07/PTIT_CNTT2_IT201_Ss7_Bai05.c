#include<stdio.h>
int partition(int a[], int l, int r) {
    //select truc la ele n-1
    int pivot=a[r];
    //idx of ele smallest
    int i=l-1;
    int temp;
    for (int j=l; j<=r-1; j++) {
        if (a[j]<pivot) {
            //mo rong vung chua cac ptu < p
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    //dat p vao pos corr => pos new of p
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}
void quick(int a[], int l, int r) {
    if (l<r) {
        int p=partition(a,l,r);
        quick(a,l,p-1);
        quick(a,p+1,r);
    }
}
void print(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}
main() {
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    if (n<=0) {
       printf("Invalid");
        return 1;
    }
    printf("before = ");
    print(a,n);
    quick(a,0,n-1);
    printf("\n after = ");
    print(a,n);
}