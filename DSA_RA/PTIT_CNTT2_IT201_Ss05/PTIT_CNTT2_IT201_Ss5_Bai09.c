#include <stdio.h>
int cols, rows;
int totalPath(int i, int j) {
    //destination => basecase stop, have 1 path valid
    if(i>=rows||j>=cols) return 0;
    if(i==rows-1&&j==cols-1) return 1;
return totalPath(i+1,j)+totalPath(i,j+1);
}
main(){
    scanf("%d %d",&cols,&rows);
    if(rows<=0||cols<=0) return 1;
    printf("(0,0) to (%d, %d): %d", rows-1, cols-1, totalPath(0,0));
}