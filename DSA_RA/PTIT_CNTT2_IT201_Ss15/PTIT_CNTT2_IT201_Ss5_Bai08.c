#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME 31
typedef struct{
    char **data;
    int front;
    int rear;
    int size;
}Queue;
Queue* createQueue(int s) {
    //cap phat queue
    Queue* q = (Queue*)malloc(sizeof(Queue));
    //cap phat arr
    q->data = (char**)malloc(sizeof(char*) * s);
    for(int i = 0; i < s; i++) {
        q->data[i] = (char*)malloc(sizeof(char) * NAME);
    }
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
void enQueue(Queue* q, char name[]) {
    if(isFull(q)) return;
    q->rear++;
    strcpy(q->data[q->rear], name);
}
//loai bo ptu dau tien
void deQueue(Queue* q) {
    if(isEmpty(q)) return;
    printf("%s\n",q->data[q->front]);
    q->front++;
}
void print(Queue* q) {
    // printf("%d\n", q->front);
    // printf("%d\n", q->rear);
    // printf("%d\n", q->size);
    // if (isEmpty(q)) return;
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d. %s\n", i-q->front+1, q->data[i]);
    }
    printf("\n");
}
void freeQueue(Queue* q) {
    for (int i=0; i < q->size; i++) {
        free(q->data[i]);
    }
    free(q->data);
    free(q);
}
main(){
    Queue* qOld = createQueue(100);
    Queue* qNormal = createQueue(100);
    char name[NAME];
    int age;
    fgets(name, NAME, stdin);
    name[strcspn(name, "\n")] = 0;
    scanf("%d", &age);
    getchar();
    if (age>=60) {
        enQueue(qOld, name);
    }else {
        enQueue(qNormal, name);
    }
    if (!isEmpty(qOld)) {
        deQueue(qOld);
    }else if (!isEmpty(qNormal)) {
        deQueue(qNormal);
    }
    print(qOld);
    print(qNormal);
    freeQueue(qOld);
    freeQueue(qNormal);
}