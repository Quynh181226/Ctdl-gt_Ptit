#include<stdio.h>
#include<stdlib.h>
int a[100];
//kcach between a, b
int absEl(int a, int b) {
    return abs(a-b);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void distanceSort(int n, int m) {
 for (int i=0; i<n-1; i++) {
     for (int j=i+1; j<n; j++) {
         int x=absEl(a[i],m);
         int y=absEl(a[j],m);
         if(x>y||x==y&&a[i]>a[j]) {
             swap(&a[i],&a[j]);
         }
     }
 }
}
main() {
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int m; scanf("%d",&m);
    distanceSort(m,m);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}