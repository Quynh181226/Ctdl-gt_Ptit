#include<stdio.h>
#include <stdlib.h>

int max(int **a, int n) {
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i][i];
    return sum;
}
int min(int **a, int n) {
     int sum=0;
     for(int i=0;i<n;i++) sum+=a[i][n-1-i];
     return sum;
}
main() {
    int cols, rows; scanf("%d %d",&rows,&cols);
    if (rows<=0 && cols<=0){
    printf("Invalid rows and cols");
    return 1;
    }else if (rows<=0){
    printf("Invalid rows");
    return 1;
    }else if (cols<=0){
    printf("Invalid cols");
    return 1;
    }
    int **a=(int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++) {
        a[i]=(int *)malloc(cols*sizeof(int));
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    if(rows==cols) {
        printf("%d",a[i][i]);
        printf("%d",a[i][cols-1]);
    }else{
        printf("%d",a[i][i]);
        printf("Invalid cols");
    }
    for(int i=0;i<rows;i++) free(a[i]);
    free(a);
}