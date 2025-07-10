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

main(){
    Queue* q = createQueue(100);
    char name[NAME];
    int choice;
    do {
        printf("1. Add new customers\n");
        printf("2. Customer service\n");
        printf("3. Display waiting customer list\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                fgets(name, NAME, stdin);
                name[strcspn(name, "\n")] = 0;
                enQueue(q, name);
                break;
            case 2:
                deQueue(q);
                break;
            case 3:
                print(q);
                break;
            case 4:
                exit(0);
        }
    }while(choice!=4);

    for (int i=0; i < q->size; i++) {
        free(q->data[i]);
    }
    free(q->data);
    free(q);
}