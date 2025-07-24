#include<stdio.h>
#include <stdlib.h>
int n, m, s, u, v;
int ke[1001][1001];
int sz[1001], visited[1001];
int cmp(void *a, void *b) {
    return *(int*)b - *(int*)a;
}
void nhap() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        sz[i]=0;
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        ke[u][sz[u]++]=v;
        ke[v][sz[v]++]=u;
    }
    scanf("%d", &s);
    for (int i=0; i<n; i++) {
        qsort(ke[i], sz[i], sizeof(int), cmp);
    }
}
void dfs(int u) {
    visited[u]=1;
    printf("%d ", u);
    for (int i=0; i<sz[u]; i++) {
        int v=ke[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}
main() {
    nhap();
    for (int i=1; i<=n; i++) {
        visited[i]=0;
    }
    dfs(s);
}