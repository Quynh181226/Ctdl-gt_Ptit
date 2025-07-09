#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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
int palindrome(char str[]) {
   stack s=createStack(strlen(str));
    for(int i=0;i<strlen(str);i++) {
        push(&s, str[i]);
    }
    //ss tung ky tu trg chuoi vs ky tu lay ra tu stack
    for (int i=0; i<strlen(str); i++) {
        if (str[i]!=pop(&s)) {
            free(s.data);
            return 0;
        }
    }
    free(s.data);
    return 1;
}
main(){
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    if (palindrome(str)) {
        printf("Palindrome");
    }else {
        printf("Not a palindrome");
    }
}