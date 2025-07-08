#include<stdio.h>
#include <stdlib.h>

// #define max 100
typedef struct{
    int *data;
    int top;
    int cap;
}stack;
stack createStack(int cap) {
    stack s;
    s.data=(int*)malloc(cap*sizeof(int));
    s.top = -1;
    s.cap = cap;
    return s;
}
// void initStack(stack *s) {
//     s->top = -1;
// }
int isFull(stack *s) {
    return s->top == s->cap - 1;
}
int isEmpty(stack *s) {
    //nếu = 0 thì ngắn xếp có phần tử
    //nếu = 1 thì ngăn xếp ko có phần tử
    return s->top == -1;
}
int top(stack *s) {
    //ktra ngăn xếp có chứa ptu hay ko
    if(isEmpty(s)) return -1;
    return s->data[s->top];
}
int pop(stack *s) {
    if(isEmpty(s)) return -1;
    return s->data[s->top--];
}
void push(stack *s, int x) {
    if(isFull(s)) return;
    s->data[++s->top] = x;
}
int size(stack *s) {
    return s->top + 1;
}
void printStack(stack *s) {
    for(int i=s->top;i>-1;i--) {
        printf("%d ",s->data[i]);
    }
}
main(){
    stack s=createStack(5);
    // initStack(&s);
    // push(&s, 1);
    // push(&s, 8);
    // push(&s, 3);
    // push(&s, 9);
    // push(&s, 5);
    // printf("Size is : %d\n",size(&s));
    printf("%d", s.cap);
    // printStack(&s);
    free(s.data);
}