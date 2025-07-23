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
typedef struct QNode{
    Node* data;
    struct QNode* next;
} QNode;
typedef struct {
   QNode *front;
   QNode *rear;
} Queue;
void initQueue(Queue* q){
    q->front=NULL;
    q->rear=NULL;
}
int isEmpty(Queue* q){
    return q->front==NULL;
}
void enQueue(Queue* q, Node* node){
    QNode* newNode=(QNode*)malloc(sizeof(QNode));
    if(newNode==NULL) return;
    newNode->data=node;
    newNode->next=NULL;
    if(q->rear==NULL){
        q->rear=q->front=newNode;
    }else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}
Node* deQueue(Queue* q){
    if(isEmpty(q)) return NULL;
    QNode* front=q->front;
    Node* item=front->data;
    q->front=front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(front);
    return item;
}
Node* createNode(int val) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL) return NULL;
    // scanf("%d", &(newNode->data));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void addNode(Node* root, int key){
    if(root==NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while(!isEmpty(&q)){
        Node* curr=deQueue(&q);
        if(curr->left==NULL){
            curr->left=createNode(key);
            return;
        }else{
            enQueue(&q, curr->left);
        }
        if(curr->right==NULL){
            curr->right=createNode(key);
            return;
        }else{
            enQueue(&q, curr->right);
        }

    }
}
void levelOrder(Node* root){
    if(root==NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while(!isEmpty(&q)){
        Node* curr=deQueue(&q);
        printf("%d ", curr->data);
        if(curr->left) enQueue(&q, curr->left);
        if(curr->right) enQueue(&q, curr->right);
    }
}
main() {
    Node* root = createNode(5);
    root->left=createNode(8);
    root->right=createNode(7);
    //if (root!=NULL){
    //    inorder(root);
    //}
    addNode(root, 1);
    addNode(root, 4);
    addNode(root, 11);
    levelOrder(root);
}