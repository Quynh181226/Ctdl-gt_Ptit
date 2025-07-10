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
    q->size = 0;
}
void print(Queue* q) {
    printf("%d\n", q->front);
    printf("%d\n", q->rear);
    printf("%d\n", q->size);
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d\n", q->data[i]);
    }
}
main(){
    Queue* q = createQueue(10);
    print(q);
    free(q);
    free(q->data);
}