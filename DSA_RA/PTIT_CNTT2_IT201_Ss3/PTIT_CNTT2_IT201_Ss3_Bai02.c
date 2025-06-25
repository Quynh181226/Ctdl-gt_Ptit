#include <stdio.h>
#include <stdlib.h>
main() {
    int n; scanf("%d",&n);
    if (n<=0||n>1000) {
        printf("Invalid");
        return 0;
    }
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int temp=a[0], maxCnt=0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for (int j=0;j<n;j++) {
            if (a[i]==a[j]) cnt++;
        }
        if (cnt>=maxCnt) {
            maxCnt=cnt;
            temp=a[i];
        }
    }
    printf("max=%d",temp);
    free(a);
}