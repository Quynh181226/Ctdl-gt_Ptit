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
void postorder(Node* root) {
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->right=createNode();
    if (root!=NULL) {
        postorder(root);
    }
    free(root);
}