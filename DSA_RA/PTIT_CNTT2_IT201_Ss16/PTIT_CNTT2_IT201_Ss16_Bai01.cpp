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
main() {
    return 0;
}