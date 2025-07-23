#include <stdio.h>
void addEdge(int n, int a[n][n], int u, int v){
    if(u>=0&&u<n&&v>=0&&v<n){
        a[u][v]=1;
        a[v][u]=1;
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
    int n=4, a[4][4]={0};
    addEdge(n, a, 1, 0);
    addEdge(n, a, 1, 2);
    addEdge(n, a, 2, 0);
    print(n, a);
}