#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    // if (x>y) return 1;
    // else if (x<y) return -1;
    // else return 0;
    return x-y;
}
bool binary(int *a, int l, int r, int f) {
    if(l>r) return false;
    int mid=(l+r)/2;
    if (a[mid]==f) return mid;
    else if (a[mid]<f) return binary(a, mid+1, r, f);
    else return binary(a, l, mid-1, f);
}
main() {
    int n; scanf("%d",&n);
    int *a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int f; scanf("%d",&f);
    qsort(a,n,sizeof(int),cmp);
    if (binary(a,0, n-1, f)) printf("Element have a arr");
    else printf("Element not have a arr");
    free(a);
}
