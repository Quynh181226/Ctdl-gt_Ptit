#include<stdio.h>
#include<stdlib.h>
int a[101][101];
void init(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            a[i][j]=0;
        }
    }
}
void addEdge(int u, v) {
    a[u][v]=1;
    a[v][u]=1;
}
void print(int a[][101], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
main() {
    int n; scanf("%d", &n);
    init(n);
    int m; scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    print(a, n);
}