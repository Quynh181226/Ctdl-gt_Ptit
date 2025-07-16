//
// Created by TDG on 16/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char content[201];
} Ques;
typedef struct Node {
    Ques ques;
    struct Node *next;
};
typedef struct {
    int top;
} Stack;
typedef struct {
  Node* front;
  Node* rear;
} Queue;
void initStack(Stack *s) {
    s->top=NULL;
}
int isEmptyStack(Stack *s) {
    return s->top=NULL;
}
void initQueue(Queue *q) {
    q->front=q->rear=NULL;
}
int isEmptyQueue(Queue *q) {
    return q->front==NULL;
}
void push(Stack* s, Ques ques) {
    Node* newNode=(Node* )malloc(sizeof(Node));
    newNode->ques=ques;
    newNode->next=s->top;
    s->top=newNode;
}
void enQueue(Queue *q, Ques ques) {
    Node* newNode=(Node* )malloc(sizeof(Node));
    newNode->ques=ques;
    newNode->next=NULL;
    if(isEmptyQueue(q)) {
        q->front=q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}
main() {
    Stack pra;
    Queue ques;
    initStack(&pra);
    initQueue(&ques);
    int choice;
    do {
        printf("Interview manager\n");
        printf("1. pratice\n");
        printf("2. undo\n");
        printf("3. redo\n");
        printf("4. history\n");
        printf("5. exit\n");
        printf("Input choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                int id=1;
                Ques ques;
                ques.id=id;
                printf("Content: ");
                fgets(ques.content,201,stdin);
                ques.content[strlen(ques.content)-1]='\0';
                push(&pra,ques);
                enQueue(&ques,ques);
                id++;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thoat chuong trinh");
                return 0;
            default:
                printf("Lua chon ko hop le");
                break;
        }
    }while (choice!=5);
}