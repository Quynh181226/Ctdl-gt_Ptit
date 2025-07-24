#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
int n, m;
Node* a[101];
Node* createNode(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void addEdge(int u, int v) {
    Node* V=createNode(v);
    V->next=a[u];
    a[u]=V;
    Node* U=createNode(u);
    U->next=a[v];
    a[v]=U;
}
//dem so lg dinh ke u
int cntNum(int u) {
    int cnt=0;
    Node* tmp=a[u];
    while (tmp!=NULL) {
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}
void Free() {
    for (int i=0; i<n; i++) {
        Node* tmp=a[i];
        while (tmp!=NULL) {
            Node* node=tmp;
            tmp=tmp->next;
            free(node);
        }
    }
}
main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    int x; scanf("%d", &x);
    printf("So dinh ke vs %d la: %d", x, cntNum(x));
    Free();
}