#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
node* createNode(int x) {
    node* head=malloc(sizeof(node));
    head->data=x;
    head->next=NULL;
}
node *revese(node* head) {
    node* tmp=head;
    node* prev=NULL;
    node* next=NULL;
    while (tmp!=NULL) {
        next = tmp->next;
        tmp->next=prev;
        prev=tmp;
        tmp=next;
    }
    return prev;
}
void print(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head=head->next;
    }
}
main() {
    node* head=createNode(10);
    head->next=createNode(20);
    head->next->next=createNode(30);
    head->next->next->next=createNode(40);
    head->next->next->next->next=createNode(50);
    head=revese(head);
    print(head);
}