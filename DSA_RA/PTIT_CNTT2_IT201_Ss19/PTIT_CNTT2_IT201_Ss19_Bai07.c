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
void bfs(Node** root, int key) {
    Node* newNode=(Node*) malloc(sizeof(Node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    if (*root==NULL) {
        *root=newNode;
        return;
    }
    queue* q=createQueue(9);
    enQueue(q, *root);
    while (!isEmpty(q)) {
        Node* curr=deQueue(q);
        if (curr->left==NULL) {
            curr->left=newNode;
            free(q->item);
            free(q);
            return;
        }else {
            enQueue(q, curr->left);
        }
        if (curr->right==NULL) {
           curr->right=newNode;
            free(q->item);
            free(q);
            return;
        }else {
            enQueue(q, curr->right);
        }
    }
    free(q->item);
    free(q);
}
// duyet preorder de ktra tree
void preorder(Node* root) {
     if (root==NULL) return;
     printf("%d ", root->data);
     preorder(root->left);
     preorder(root->right);
}
Node* createNode() {
    int val; scanf("%d", &val);
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    //input integer
    // scanf("%d", &(newNode->data));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->right=createNode();
    // preorder(root);
    int x; scanf("%d", &x);
    bfs(&root, x);
    preorder(root);
}