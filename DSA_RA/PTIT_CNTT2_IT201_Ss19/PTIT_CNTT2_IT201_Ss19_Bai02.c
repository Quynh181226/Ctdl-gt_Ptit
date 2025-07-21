//
// Created by TDG on 21/07/2025.
//
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode() {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    //input integer
    scanf("%d", &(newNode->data));
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preorder(Node* root) {
    if (root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->right=createNode();
    if (root!=NULL) {
      preorder(root);
    }
    free(root);
}