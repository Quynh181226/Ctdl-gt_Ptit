#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// #define max 100
typedef struct{
    char *data;
    int top;
    int cap;
}stack;
stack createStack(int cap) {
    stack s;
    s.data=(char*)malloc(cap*sizeof(char));
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
char top(stack *s) {
    //ktra ngăn xếp có chứa ptu hay ko
    if(isEmpty(s)) return -1;
    return s->data[s->top];
}
char pop(stack *s) {
    if(isEmpty(s)) return -1;
    return s->data[s->top--];
}
//dua dlieu vao not tra ve
void push(stack *s, char x) {
    if(isFull(s)) return;
    s->data[++s->top] = x;
}
int size(stack *s) {
    return s->top + 1;
}
int prio(char c){
    if (c=='+'|| c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    return 0;
}
void coverPostfix(char *s) {
    stack st=createStack(strlen(s));
    for (int i = 0; s[i]!='\0'; i++ ) {
        if (isalnum(s[i])) {
            //in toan hang
            printf("%c",s[i]);
        }else if (s[i]=='(') {
            push(&st,s[i]);
        }else if (s[i]==')') {
            //pop all den khi see '('
            while (!isEmpty(&st)&&top(&st)!='(') {
                printf("%c",pop(&st));
            }
            //'('
            pop(&st);
        }else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
            //see toan tu -> proces by prio
            while (!isEmpty(&st)&&prio(top(&st))>=prio(s[i])) {
                //pop prio level level high highher
                printf("%c",pop(&st));
            }
            push(&st,s[i]);
        }
    }
    //duyet xg pop all toan tu con lai
    while (!isEmpty(&st)) {
        printf("%c",pop(&st));
    }
    free(st.data);
}

main(){
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    coverPostfix(s);
}