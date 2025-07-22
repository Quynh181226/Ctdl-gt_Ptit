//
// Created by TDG on 22/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode() {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    scanf("%d", &(newNode->data));
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
main() {
    Node* root = createNode();
    root->left=createNode();
    root->right=createNode();
    if (root!=NULL){
        inorder(root);
    }
}