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
bool binary(int *a, int n, int f) {
    int l=0, r=n-1;
    while (l<=r) {
        //tinh chi so cua ptu o giua
        int mid=(l+r)/2;
        if (a[mid]==f) return true;
        else if (a[mid]<f) l=mid+1;
        else r=mid-1;
    };
    return false;
}
main() {
    int n; scanf("%d",&n);
    int *a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int f; scanf("%d",&f);
    qsort(a,n,sizeof(int),cmp);
    if (binary(a, n, f)) printf("Element have a arr");
    else printf("Element not have a arr");
    free(a);
}
