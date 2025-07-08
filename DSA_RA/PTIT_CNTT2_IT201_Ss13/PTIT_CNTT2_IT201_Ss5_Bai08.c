#include <ctype.h>
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
int eval(int a, int b, int c) {
    if (c=='+') return a+b;
    if (c=='-') return a-b;
    if (c=='*') return a*b;
    if (c=='/') {
        if (b==0) {
            return 0;
        }
        return a/b;
    }
    return 0;
}
int evalPosFix(char s[]) {
    stack st=createStack(strlen(s));
    for (int i=0; s[i]!='\0'; i++) {
        if (isdigit(s[i])) {
            push(&st,s[i]-'0');
        }else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
            int a = pop(&st);
            int b = pop(&st);
            int kq=eval(b, a, s[i]);
            push(&st, kq);
        }
    }
    int ans=pop(&st);
    free(st.data);
    return ans;
}
main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strlen(s)-1] = '\0';
    printf("%d", evalPosFix(s));
}