#include<stdio.h>
main() {
    int n, a[101][101];
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int cnt=0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if(a[i][j]==1) {
               cnt++;
            }
        }
    }
    printf("%d", cnt);
}