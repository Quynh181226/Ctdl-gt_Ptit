#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// #define max 100
typedef struct{
    char **data;
    int top;
    int cap;
}stack;
stack createStack(int cap) {
    stack s;
    s.data=(char**)malloc(cap*sizeof(char*));
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
char* top(stack *s) {
    //ktra ngăn xếp có chứa ptu hay ko
    if(isEmpty(s)) return -1;
    return s->data[s->top];
}
char* pop(stack *s) {
    if(isEmpty(s)) return -1;
    return s->data[s->top--];
}
//dua dlieu vao not tra ve
void push(stack *s, char *x) {
    if(isFull(s)) return;
    s->data[++s->top] = strdup(x);
}
int size(stack *s) {
    return s->top + 1;
}
void freeStack(stack *s) {
    for(int i=0; i <= s->top; i++) {
        free(s->data[i]);
    }
    free(s->data);
    s->top=-1;
    s->cap=0;
}
void coverInfix(char *s) {
    stack st=createStack(strlen(s));
    for (int i = 0; s[i]!='\0'; i++ ) {
        if (isalnum(s[i])) {
            char tmp[]={s[i], '\0'};
            push(&st, tmp);
        }else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
            char *b=pop(&st);
            char *a=pop(&st);
            char snew[10001];
            sprintf(snew, "(%s%c%s)", a, s[i], b);
            push(&st, snew);
            free(a);
            free(b);
        }
    }
    char *res=pop(&st);
    printf("%s", res);
    free(res);
    freeStack(&st);
}

main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
   coverInfix(s);
}