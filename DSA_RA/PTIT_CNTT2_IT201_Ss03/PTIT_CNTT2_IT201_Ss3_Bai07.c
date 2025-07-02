#include <stdio.h>
#include <stdlib.h>
int sumRow(int **a, int cols, int k) {
    int tmp = 0;
    for (int i = 0; i < cols; i++) tmp += a[k - 1][i];
    return tmp;
}
main() {
    int n, m;   scanf("%d %d", &n, &m);
    if (n < 1 || n > 1000) {
        printf("Invalid rows");
        return 1;
    }else if (m < 1 || m > 1000) {
        printf("Invalid cols");
        return 1;
    }
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int k;  scanf("%d", &k);
    if (k > n || k < 0) {
        printf("Invalid rows");
        return 1;
    }
    printf("sum=%d", sumRow(a, n, k));
    for (int i = 0; i < n; i++)  free(a[i]);
    free(a);
}