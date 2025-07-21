//
// Created by TDG on 21/07/2025.
//

//
// Created by TDG on 21/07/2025.
//
#include<stdio.h>
#include <stdlib.h>
// duyet theo chieu sau: DFS
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
typedef struct Student {
    int id;
    char name[20];
} Student;
Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    //input integer
    // scanf("%d", &(newNode->data));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//B2: Trien khai DFS
//Cach 1: Dung Inorder(LNR LEFT-NODE-RIGHT)
void inorder(Node* root) {
    if (root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
//Cach 2: Dung Preorder(NLR NODE_LEFT-RIGHT)
void preorder(Node* root) {
    if (root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
//Cach 3: Dung Postorder(LRN LEFT-RIGHT_NODE)
void postorder(Node* root) {
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
//B3: Tao cay(TREE) trien khai trong main
main() {
    Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    printf("Duyet cay theo Inorder: ");
    inorder(root);
    printf("\nDuyet cay theo Preorder: ");
    preorder(root);
}