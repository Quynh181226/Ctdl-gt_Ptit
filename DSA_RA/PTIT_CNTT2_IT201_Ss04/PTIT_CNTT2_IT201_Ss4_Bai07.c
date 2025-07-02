#include<stdio.h>
#include<stdlib.h>
main() {
    int n; scanf("%d",&n);
    int *a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int check=0;
    for(int i=0;i<n/2;i++) {
        if (a[i]==a[n-1-i]) {
            printf("(%d %d)\n",a[i],a[n-1-i]);
            check=1;
        }
    }
    if(check==0) printf("Not symmetrical pair");
    free(a);
}