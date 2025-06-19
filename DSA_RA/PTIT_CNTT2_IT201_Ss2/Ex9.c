#include <stdio.h>
#include <stdlib.h>
main() {
    int n; scanf("%d",&n);
    int *a=(int *)malloc(n * sizeof(int));

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int *b=(int *)calloc(100, sizeof (int));
    for (int i=0; i<n; i++) b[a[i]]++;

    int cnt=0;
    for (int i=0; i<n; i++) {
        if (b[a[i]]>cnt) cnt=b[a[i]];
    }

    for (int i=0; i<n; i++) {
        if (b[a[i]]==cnt) {
            printf("%d",a[i]);
            break;
        }
    }
    free(a);
    free(b);
}