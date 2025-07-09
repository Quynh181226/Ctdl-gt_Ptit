#include<stdio.h>
#include<stdlib.h>
// #include<>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
} Stack;
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void initStack(Stack* s) {
    s->top = NULL;
}
int isEmpty(Stack* s) {
    return s->top==NULL;
}
int top(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->top->data;
}
void push(Stack* s, int val) {
    Node* newNode = createNode(val);
    newNode->next = s->top;
    s->top = newNode;
}
void printStack(Stack* s) {
    if (s->top == NULL) return;
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
main() {
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printStack(&s);
}