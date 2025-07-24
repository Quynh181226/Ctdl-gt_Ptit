//
// Created by TDG on 22/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node*a[101];
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
void print(){
    for(int i=0; i<n; i++){
    printf("%d:", i);
    Node* tmp=a[i];
    while(tmp!=NULL){
        printf(" %d", tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
    }
}
void Free(){
    for(int i=0; i<n; i++){
        Node* tmp=a[i];
            while(tmp){
            Node* node=tmp;
            tmp=tmp->next;
            free(node);
        }
    }
}
main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        a[i]=NULL;
    }
    int u, v;
    while (scanf("%d %d", &u, &v)==2) {
        addEdge(u, v);
    }
    print();
    Free();
}

main() {
    int n, u, v;
    int ke[101][101], sz[101] = {0};

    scanf("%d", &n);
    while(scanf("%d %d", &u, &v) == 2) {
        ke[u][sz[u]++] = v;
        ke[v][sz[v]++] = u;
    }

    for(int i = 0; i < n; i++) {
        printf("%d:", i);
        for(int j = 0; j < sz[i]; j++) {
            printf(" %d", ke[i][j]);
        }
        printf("\n");
    }
}