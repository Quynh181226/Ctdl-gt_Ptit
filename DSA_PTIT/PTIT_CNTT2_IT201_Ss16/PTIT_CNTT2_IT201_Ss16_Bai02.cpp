//
// Created by TDG on 13/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct queue {
    struct node *front, *rear;
}queue;
queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
node *createNode(int data) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) return NULL;
    n->data = data;
    n->next = NULL;
    return n;
}
void enqueue(queue *q, int data) {
    // node* tmp=(node*)malloc(sizeof(node));
    node *newNode = createNode(data);
    if (q->front == NULL) {
        q->front = q->rear = newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}
void printQueue(queue *q) {
    node *tmp = q->front;
    while (n != NULL) {
        printf("%d ", n->data);
        tmp=tmp->next;
    }
    if (q->rear != NULL) {
        printf("rear->%d->NULL", q->rear->data);
    }else {
        printf("rear->NULL");
    }
}
main() {
    queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    printQueue(q);
}