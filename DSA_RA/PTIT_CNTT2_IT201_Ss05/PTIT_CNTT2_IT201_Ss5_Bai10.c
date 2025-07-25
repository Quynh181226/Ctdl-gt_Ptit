#include <stdio.h>
int cols, rows, rowsBlock, colsBlock;
int totalPath(int i, int j) {
    //invalid => not path valid
    if(i>=rows||j>=cols) return 0;
    //destination => basecase stop, have 1 path valid
    if(i==rows-1&&j==cols-1) return 1;
    if (i==rowsBlock-1&&j==colsBlock-1) return 0;
    return totalPath(i+1,j)+totalPath(i,j+1);
}
main(){
    scanf("%d %d", &rows, &cols);
    if(rows<=0||cols<=0) return 1;
    scanf("%d %d",&rowsBlock,&colsBlock);
    if (rowsBlock<=0||colsBlock<=0||rowsBlock>rows||colsBlock>cols) return 1;
    printf("(0,0) to (%d, %d): %d", rows-1, cols-1, totalPath(0,0));
}