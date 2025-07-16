//
// Created by TDG on 15/07/2025.
//
#include <string.h>
#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    char* command;
    struct Node* next;
} Node;
typedef struct Stack {
    Node* top;
} Stack;
void initStack(Stack* s) {
    s->top = NULL;
}
Node* createNode(char* command) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->command=strdup(command);
    if (newNode->command == NULL) {
        free(newNode);
        return NULL;
    }
    newNode->next=NULL;
    return newNode;
}
void push(Stack* s, char* command) {
    Node* newNode=createNode(command);
    if (newNode==NULL) return;
    newNode->next=s->top;
    s->top=newNode;
}
char* pop(Stack* s) {
    if (s->top==NULL) return NULL;
    Node* tmp=s->top;
    char* command=tmp->command;
    s->top=tmp->next;
    free(tmp);
    return command;
}
void clearStack(Stack* s) {
    while (s->top!=NULL) {
        Node* tmp=s->top;
        s->top=tmp->next;
        free(tmp->command);
        free(tmp);
    }
}
//in lich sư lenh(ms nhat den cu nhat)
void displayHistory(Stack* s) {
    if (s->top==NULL) {
        printf("lich su trong\n");
        return;
    }
    printf("lich su lenh: ");
    Node* tmp=s->top;
    while (tmp!=NULL) {
        printf("%s ", tmp->command);
        tmp=tmp->next;
    }
}
main() {
    Stack historyStack, redoStack;
    initStack(&historyStack);
    initStack(&redoStack);
    int choice;
    char command[100];
    while (1) {
        printf("\n=====Terminal history\n");
        printf("1. insert\n");
        printf("2. undo\n");
        printf("3. redo\n");
        printf("4. display\n");
        printf("5. exit\n");
        printf("nhap lua chon: ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                printf("nhap lenh: ");
                fgets(command, 100, stdin);
                command[strcspn(command, "\n")]='\0';
                push(&historyStack, command);
                clearStack(&redoStack);
                break;
            case 2:
                if (historyStack.top==NULL) {
                    printf("ko co lenh de hoan tac\n");
                }else {
                    char* undo=pop(&historyStack);
                    if (undo!=NULL) {
                        push(&redoStack, undo);
                        printf("da hoan tac lenh: %s\n", undo);
                        free(undo);
                    }
                }
                break;
            case 3:
                if (redoStack.top==NULL) {
                    printf("ko co lenh de phuc hoi\n");
                }else {
                    char* redo=pop(&redoStack);
                    if (redo!=NULL) {
                        push(&historyStack, redo);
                        printf("da phuc hoi lenh %s\n");
                        free(redo);
                    }
                }
                break;
            case 4:
                displayHistory(&historyStack);
                break;
            case 5:
                printf("thoat chuong trinh");
                clearStack(&historyStack);
                clearStack(&redoStack);
                return 0;
            default:
                printf("lua chon hop le");
        }
    }
}
