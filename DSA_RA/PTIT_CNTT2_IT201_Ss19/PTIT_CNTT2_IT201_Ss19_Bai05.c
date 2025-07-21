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
bool dfs(Node* root, int key) {
    if (root==NULL) return false;
    if (root->data==key) return true;
    if (dfs(root->left, key)) return true;
    return dfs(root->right, key);
}
main() {
    Node* root=createNode();
    root->left=createNode();
    root->right=createNode();
    int x; scanf("%d", &x);
    if (dfs(root, x)) printf("True");
    else printf("False");
}