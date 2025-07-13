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
void dequeue(queue *q) {
    node *tmp = q->front;
    if (q->front == NULL) {
        return;
    }
    // else {
    printf("%d", tmp->data);
    free(tmp);
    q->front=q->front->next;
    // }
    if (q->front == NULL) {
        q->rear=NULL;
    }
    free(tmp);
}
void printQueue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    node *tmp = q->front;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp=tmp->next;
    }
}
main() {
    queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 33);
    enqueue(q, 44);
    enqueue(q, 55);
    printQueue(q);
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}