#include <stdio.h>
void addEdge(int n, int a[n][n], int u, int v){
    if(u>=0&&u<n&&v>=0&&v<n){
        a[u][v]=1;
    }
}
void print(int n, int a[n][n]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
main() {
    int n=3, a[3][3]={0};
    addEdge(n, a, 0, 1);
    // addEdge(n, a, 0, 2);
    addEdge(n, a, 1, 2);
    print(n, a);
}