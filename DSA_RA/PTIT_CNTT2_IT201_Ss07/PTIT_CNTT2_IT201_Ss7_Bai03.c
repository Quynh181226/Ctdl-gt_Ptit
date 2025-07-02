#include <stdio.h>
int a[100];
void insert(int n) {
    int key, j;
    for (int i=1; i<n; i++) {
        key = a[i];
        // j=i-1;
        //di chuyen cac ptu lon hon key sang phai
        // while (j>=0&&a[j]>key) {
        for (j=i-1; j>=0; j--) {
            if (a[j]>key) a[j+1]=a[j];
            else break;
            // a[j+1]=a[j];
            // j=j-1;
        }
        a[j+1]=key;
    }
}
void print(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}
main() {
    int n; scanf("%d",&n);
    if (n<=0||n>=1000) return 1;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    printf("before: ");
    print(a,n);
    printf("\n");
    insert(n);
    printf("after: ");
    print(a, n);
}