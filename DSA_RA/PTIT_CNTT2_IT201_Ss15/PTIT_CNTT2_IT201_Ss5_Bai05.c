#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *data;
    int front;
    int rear;
    int size;
}Queue;
Queue* createQueue(int s) {
    //cap phat queue
    Queue* q = (Queue*)malloc(sizeof(Queue));
    //cap phat arr
    q->data = (int*)malloc(sizeof(int) * s);
    q->front = 0;
    q->rear = -1;
    q->size = s;
    return q;
}
int isFull(Queue* q) {
    return q->rear == q->size - 1;
}
int isEmpty(Queue* q) {
    return q->front>q->rear;
}
//them ptu cua queue
void enQueue(Queue* q, int x) {
    if(isFull(q)) return;
    q->rear++;
    q->data[q->rear] = x;
}
//loai bo ptu dau tien
int deQueue(Queue* q) {
    if(isEmpty(q)) return;
    int x = q->data[q->front];
    q->front++;
    return x;
}
void print(Queue* q) {
    // printf("%d\n", q->front);
    // printf("%d\n", q->rear);
    // printf("%d\n", q->size);
    // if (isEmpty(q)) return;
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
main(){
    Queue* q = createQueue(5);
    // int x;
    // for(int i=1; i<=5; i++) {
    //     scanf("%d", &x);
    //     enQueue(q, x);
    // }
    enQueue(q, 10);
    enQueue(q, 20);
    print(q);
    deQueue(q);
    print(q);
    free(q->data);
    free(q);
}