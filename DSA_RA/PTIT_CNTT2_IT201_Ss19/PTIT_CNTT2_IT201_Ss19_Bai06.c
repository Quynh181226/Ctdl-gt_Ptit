//
// Created by TDG on 21/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
typedef struct queue {
    Node** item;
    int front, rear;
    int cap;
} queue;
queue* createQueue(int cap) {
    queue* q=(queue*) malloc(sizeof(queue));
    q->item=(Node**)malloc(sizeof(Node*)*cap);
    q->front=0;
    q->rear=-1;
    q->cap=cap;
    return q;
}
int isEmpty(queue* q) {
    return q->rear < q->front;
}
void enQueue(queue* q, Node* node) {
    if (q->rear+1 < q->cap) {
        q->item[++q->rear]=node;
    }
    //#->full
}
Node* deQueue(queue* q) {
    if (!isEmpty(q)) {
        return q->item[q->front++];
    }
    return NULL;
}
bool bfs(Node* root, int key) {
    if (root==NULL) return false;
    queue* q=createQueue(9);
    enQueue(q, root);
    while (!isEmpty(q)) {
        Node* curr=deQueue(q);
        if (curr->data==key) {
            free(q->item);
            free(q);
            return true;
        }
        if (curr->left!=NULL) {
            enQueue(q, curr->left);
        }
        if (curr->right!=NULL) {
            enQueue(q, curr->right);
        }
    }
    free(q->item);
    free(q);
    return false;
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->right=createNode();
    int x; scanf("%d", &x);
    if (bfs(root, x)) printf("True");
    else printf("False");
}