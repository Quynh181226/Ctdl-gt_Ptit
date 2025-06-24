#include<stdio.h>
#include <stdlib.h>

int max(int **a, int rows, int cols) {
    int max=a[0][0];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(a[i][j]>max) {
                max=a[i][j];
            }
        }
    }
    return max;
}
int min(int **a, int rows, int cols) {
    int min=a[0][0];
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(a[i][j]<min) {
                min=a[i][j];
            }
        }
    }
    return min;
}
main() {
    int cols, rows; scanf("%d %d",&rows,&cols);
    if (rows<=0 && cols<=0) printf("Invalid rows and cols");
    else if (rows<=0) printf("Invalid rows");
    else if (cols<=0) printf("Invalid cols");
    int **a=(int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++) {
        a[i]=(int *)malloc(cols*sizeof(int));
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf('max=%d\n',max(a,rows,cols));
    printf('min=%d',min(a,rows,cols));
    for(int i=0;i<rows;i++) free(a[i]);
    free(a);
}