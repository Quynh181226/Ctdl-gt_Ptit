#include<stdio.h>
#include<stdlib.h>
int n, a[1001][1001];
int ke[1001][1001], sz[1001];
int cmp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}
main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        sz[i]=0;
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
             if(a[i][j]==1) {
                 ke[i][sz[i]++]=j;
             }
        }
    }
    for (int i=1; i<=n; i++) {
        qsort(ke[i], sz[i], sizeof(int), cmp);
    }
    for (int i=0; i<n; i++) {
        printf("%d:", i);
        for (int j=0; j<sz[i]; j++) {
            printf(" %d", ke[i][j]);
        }
        printf("\n");
    }
}