#include <stdio.h>
main() {
    int n=3, a[3][3]={0};
    // a[0][1]=1;
    // a[1][0]=1;
    a[1][2]=1;
    a[2][1]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}