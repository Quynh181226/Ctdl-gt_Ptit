#include<stdio.h>
int a[100];
void select(int n) {
    int min, temp;
    for (int i=0; i<n-1; i++) {
        min=i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[min]) {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
void print(int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}
main() {
    int n; scanf("%d",&n);
    if (n<=0||n>=1000) return 1;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    printf("before: ");
    print(n);
    printf("\n");
    select(n);
    printf("after: ");
    print(n);
}