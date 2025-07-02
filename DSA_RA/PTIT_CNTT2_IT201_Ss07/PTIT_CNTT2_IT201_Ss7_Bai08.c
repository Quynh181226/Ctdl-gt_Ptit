#include <stdio.h>
#include <stdlib.h>
int rows, cols, k, a[100][100];
void sort() {
    for (int i=0; i<rows-1; i++) {
        for (int j=0; j<rows-i-1; j++) {
            if (a[j][k-1]>a[j+1][k-1]) {
                int tmp=a[j][k-1];
                a[j][k-1]=a[j+1][k-1];
                a[j+1][k-1]=tmp;
            }
        }
        printf("\n");
    }
}
void print() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
main() {
    scanf("%d %d", &rows, &cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &k);
    sort();
    print();
}