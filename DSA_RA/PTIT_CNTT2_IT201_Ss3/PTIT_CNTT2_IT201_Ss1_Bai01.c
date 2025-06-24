#include <stdio.h>
#include <stdlib.h>
main() {
    int n; scanf("%d",&n);
    if(n<=0) return 1;
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    free(a);
}