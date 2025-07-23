//
// Created by TDG on 22/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    // scanf("%d", &(newNode->data));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void addEdge(Node* a[], int u, int v) {
    Node* V=createNode(v);
    V->next=a[u];
    a[u]=V;
    Node* U=createNode(u);
    U->next=a[v];
    a[v]=U;
}
void print(Node* a[], int n) {
    for (int i=0; i<n; i++) {
        Node* tmp=a[i];
        while (tmp!=NULL) {
            printf("%d ", tmp->data);
            tmp=tmp->next;
        }
        printf("\n");
    }
}
main() {
   int n=4;
    Node* a[4]={NULL};
    addEdge(a, 0, 1);
    addEdge(a, 0, 2);
    addEdge(a, 1, 2);
    addEdge(a, 2, 3);;
    print(a, n);
}