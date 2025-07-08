#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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
// void printStack(stack *s) {
//     for(int i=s->top;i>-1;i--) {
//         printf("%d\n",s->data[i]);
//     }
// }
bool check(char s[]) {
    stack st=createStack(strlen(s));
   for (int i = 0; i < strlen(s); i++) {
       if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
           push(&st, s[i]);
       }else {
           if (isEmpty(&st)) {
               free(st.data);
               return false;
           }
           char top1=top(&st);
           if (top1=='('&&s[i] == ')'||top1=='{'&&s[i]=='}'||top1=='['&&s[i]==']') {
               pop(&st);
           }else {
               free(st.data);
               return false;
           }
       }
   }
    free(st.data);
    return isEmpty(&st);
}
main(){
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    if (check(str)) {
        printf("True");
    }else {
        printf("False");
    }
}