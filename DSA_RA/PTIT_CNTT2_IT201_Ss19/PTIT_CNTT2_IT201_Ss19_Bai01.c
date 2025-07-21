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
main() {
    Node* root=createNode();
    if (root!=NULL) {
        printf("%d", root->data);
    }
}