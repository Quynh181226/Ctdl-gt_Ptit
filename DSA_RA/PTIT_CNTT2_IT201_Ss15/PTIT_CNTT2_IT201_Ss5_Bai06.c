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
    if(isEmpty(q)) return -1;
    int x = q->data[q->front];
    q->front++;
    return x;
}
int check(Queue* q) {
    if(isEmpty(q)||q->front==q->rear) return 1;
    for(int i=q->front; i<q->rear; i++) {
        if (q->data[i+1] != q->data[i]+1) {
            //noo
            return 0;
        }
    }
    //yess
    return 1;
}
main(){
    int n; scanf("%d",&n);
    Queue* q = createQueue(n);
    int x;
    for(int i=1; i<=5; i++) {
        scanf("%d", &x);
        enQueue(q, x);
    }
    if (check(q)) {
        printf("true");
    }else {
        printf("false");
    }
    free(q->data);
    free(q);
}