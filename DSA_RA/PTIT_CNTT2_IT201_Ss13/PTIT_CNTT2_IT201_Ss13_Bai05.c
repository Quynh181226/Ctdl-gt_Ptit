#include<stdio.h>
#include <stdlib.h>

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
void reverse(stack *s, int a[], int n) {
    s->top = -1;
    for(int i=0;i<n;i++) {
        push(s, a[i]);
    }
    for (int i=0; i<n; i++) {
        a[i]=pop(s);
    }
}
main(){
    int n; scanf("%d",&n);
    if (n<=0) return 1;
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    stack s=createStack(n);
    reverse(&s, a, n);
    for(int i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
    // for(int i=0;i<5;i++) {
    //     scanf("%d",&n);
    //     push(&s,n);
    // }
    // printStack(&s);
    free(s.data);
}