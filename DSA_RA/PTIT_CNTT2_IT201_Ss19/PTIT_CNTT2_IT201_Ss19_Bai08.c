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
Node* createNode() {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    //input integer
    scanf("%d", &(newNode->data));
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int height(Node* root) {
    if (root==NULL) return 0;
    int heightLeft=height(root->left);
    int heightRight=height(root->right);
    int maxHeight;
    if (heightLeft>heightRight) {
        maxHeight=heightLeft;
    }else {
        maxHeight=heightRight;
    }
    return maxHeight+1;
}
int dfs(Node* root) {
    if (root==NULL) return -1;
    if (root->left==NULL&&root->right==NULL) {
        return root->data;
    }
    int l=dfs(root->left);
    int r=dfs(root->right);
    if (l==-1) return r;
    if (r==-1) return l;
    return l;
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->left->left=createNode();
    root->right=createNode();
    printf("%d", dfs(root));
}